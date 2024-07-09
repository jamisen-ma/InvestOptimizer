# Portfolio Optimizer

## Project Overview

**Portfolio Optimizer** is a tool designed to optimize investment portfolios by using advanced mathematical algorithms. This project provides a complete end-to-end solution involving data acquisition, data preprocessing, portfolio optimization, and a web interface for user interaction. It leverages Python for data handling and cleaning, C++ for computationally intensive optimization tasks, and React with Bootstrap for a modern and responsive frontend.

## Mathematical Algorithms Used

1. **Mean-Variance Optimization**:
   - This method finds the optimal portfolio allocation by maximizing expected returns for a given level of risk or minimizing risk for a given level of expected returns.
   - Utilizes the covariance matrix of asset returns to understand the risk and correlations between assets.

2. **Constraint Handling**:
   - Includes constraints such as no short-selling (i.e., weights cannot be negative).
   - Ensures that the sum of the weights is equal to 1, normalizing the portfolio weights.

3. **Matrix Operations**:
   - Eigen library is used for efficient matrix operations and solving linear equations.

# How to Run the Portfolio Optimizer Project

## Backend (Python)

**Run Backend**:
   ```bash
   cd portfolio-optimizer/backend
   python -m venv env
   source env/bin/activate
   pip install -r requirements.txt
   python src/app.py
   ```
**Run Frontend**:
  ```bash
cd portfolio-optimizer/frontend
npm install
npm start
   ```

**Run Optimization**:
  ```bash
cd portfolio-optimizer/optimization
mkdir build
cd build
cmake ..
make
  ```


**Running the Full Applicationn**:
  ```bash
cd portfolio-optimizer/backend
source env/bin/activate  # On Windows use `env\Scripts\activate`
python src/app.py
  ```