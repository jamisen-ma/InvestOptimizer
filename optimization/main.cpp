#include <iostream>
#include <fstream>
#include <vector>
#include <Eigen/Dense>
#include <unsupported/Eigen/MatrixFunctions>
#include <limits>

// Function to load CSV data into an Eigen matrix
Eigen::MatrixXd loadCSV(const std::string& path) {
    std::ifstream file(path);
    std::vector<std::vector<double>> data;
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream lineStream(line);
        std::string cell;
        std::vector<double> row;
        while (std::getline(lineStream, cell, ',')) {
            row.push_back(std::stod(cell));
        }
        data.push_back(row);
    }

    Eigen::MatrixXd matrix(data.size(), data[0].size());
    for (size_t i = 0; i < data.size(); ++i) {
        matrix.row(i) = Eigen::VectorXd::Map(&data[i][0], data[i].size());
    }

    return matrix;
}

// Function to perform portfolio optimization
Eigen::VectorXd optimizePortfolio(const Eigen::MatrixXd& returns, const Eigen::VectorXd& meanReturns, double riskFreeRate = 0.0) {
    Eigen::MatrixXd covMatrix = (returns.transpose() * returns) / (returns.rows() - 1);
    Eigen::MatrixXd invCovMatrix = covMatrix.inverse();

    Eigen::VectorXd ones = Eigen::VectorXd::Ones(meanReturns.size());
    double A = ones.transpose() * invCovMatrix * meanReturns;
    double B = meanReturns.transpose() * invCovMatrix * meanReturns;
    double C = ones.transpose() * invCovMatrix * ones;
    double D = A * C - B;

    Eigen::VectorXd lambda1 = (C * invCovMatrix * meanReturns - A * invCovMatrix * ones) / D;
    Eigen::VectorXd lambda2 = (B * invCovMatrix * ones - A * invCovMatrix * meanReturns) / D;

    Eigen::VectorXd weights = lambda1 + riskFreeRate * lambda2;
    return weights / weights.sum();  // Normalize to sum to 1
}

// Function to handle constraints
Eigen::VectorXd optimizeWithConstraints(const Eigen::MatrixXd& returns, const Eigen::VectorXd& meanReturns, double riskFreeRate = 0.0, double shortSellingLimit = 0.0) {
    Eigen::MatrixXd covMatrix = (returns.transpose() * returns) / (returns.rows() - 1);
    Eigen::MatrixXd invCovMatrix = covMatrix.inverse();

    Eigen::VectorXd ones = Eigen::VectorXd::Ones(meanReturns.size());
    double A = ones.transpose() * invCovMatrix * meanReturns;
    double B = meanReturns.transpose() * invCovMatrix * meanReturns;
    double C = ones.transpose() * invCovMatrix * ones;
    double D = A * C - B;

    Eigen::VectorXd lambda1 = (C * invCovMatrix * meanReturns - A * invCovMatrix * ones) / D;
    Eigen::VectorXd lambda2 = (B * invCovMatrix * ones - A * invCovMatrix * meanReturns) / D;

    Eigen::VectorXd weights = lambda1 + riskFreeRate * lambda2;

    // Apply constraints
    for (int i = 0; i < weights.size(); ++i) {
        if (weights[i] < shortSellingLimit) {
            weights[i] = shortSellingLimit;
        }
    }

    return weights / weights.sum();  // Normalize to sum to 1
}

int main() {
    Eigen::MatrixXd returns = loadCSV("cleaned_data.csv");

    // Calculate mean returns
    Eigen::VectorXd meanReturns = returns.colwise().mean();

    // Optimize portfolio without constraints
    Eigen::VectorXd optimalWeights = optimizePortfolio(returns, meanReturns);
    std::cout << "Optimal Weights without Constraints:\n" << optimalWeights << std::endl;

    // Optimize portfolio with constraints
    double riskFreeRate = 0.01;
    double shortSellingLimit = 0.0;  // No short-selling allowed
    Eigen::VectorXd constrainedWeights = optimizeWithConstraints(returns, meanReturns, riskFreeRate, shortSellingLimit);
    std::cout << "Optimal Weights with Constraints (No Short-Selling):\n" << constrainedWeights << std::endl;

    return 0;
}
