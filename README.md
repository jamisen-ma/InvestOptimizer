# Portfolio Optimizer

## Project Overview

You can enter in all the stocks you have and this tool will optimize your investment portfolio. It uses Python for data handling and cleaning and C++ for computationally intensive optimization tasks.
<img width="929" alt="Screenshot 2024-07-10 at 4 50 36 PM" src="https://github.com/jamisen-ma/InvestOptimizer/assets/100271213/6652312f-9fa6-41ac-9323-279e9986799c">
<img width="756" alt="Screenshot 2024-07-10 at 4 50 28 PM" src="https://github.com/jamisen-ma/InvestOptimizer/assets/100271213/c624cbcb-bb7e-41e7-9e3b-2a6fc383ea8d">
<img width="759" alt="Screenshot 2024-07-10 at 4 49 24 PM" src="https://github.com/jamisen-ma/InvestOptimizer/assets/100271213/bb8c4056-9983-450f-82ab-9893df8defea">
<img width="890" alt="Screenshot 2024-07-10 at 4 49 06 PM" src="https://github.com/jamisen-ma/InvestOptimizer/assets/100271213/b3763cfd-a893-4719-8422-0875f4448c41">

## Algorithms Used

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
