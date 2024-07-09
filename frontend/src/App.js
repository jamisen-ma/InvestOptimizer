// src/App.js

import React, { useState } from 'react';
import axios from 'axios';
import 'bootstrap/dist/css/bootstrap.min.css';

function App() {
  const [portfolio, setPortfolio] = useState([{ ticker: '', amount: '' }]);
  const [result, setResult] = useState(null);

  const handleChange = (index, event) => {
    const newPortfolio = portfolio.map((p, i) => {
      if (i === index) {
        return { ...p, [event.target.name]: event.target.value };
      }
      return p;
    });
    setPortfolio(newPortfolio);
  };

  const handleAdd = () => {
    setPortfolio([...portfolio, { ticker: '', amount: '' }]);
  };

  const handleSubmit = async (event) => {
    event.preventDefault();
    try {
      const response = await axios.post('http://localhost:5000/process_portfolio', { portfolio });
      setResult(response.data);
    } catch (error) {
      console.error('There was an error processing your request!', error);
    }
  };

  return (
    <div className="container mt-5">
      <h1 className="text-center mb-4">Portfolio Optimizer</h1>
      <form onSubmit={handleSubmit} className="mb-4">
        {portfolio.map((entry, index) => (
          <div className="form-row mb-3" key={index}>
            <div className="col">
              <input
                type="text"
                className="form-control"
                name="ticker"
                placeholder="Ticker"
                value={entry.ticker}
                onChange={(e) => handleChange(index, e)}
              />
            </div>
            <div className="col">
              <input
                type="number"
                className="form-control"
                name="amount"
                placeholder="Amount"
                value={entry.amount}
                onChange={(e) => handleChange(index, e)}
              />
            </div>
          </div>
        ))}
        <div className="form-row">
          <div className="col">
            <button type="button" className="btn btn-secondary btn-block" onClick={handleAdd}>Add Stock</button>
          </div>
          <div className="col">
            <button type="submit" className="btn btn-primary btn-block">Optimize Portfolio</button>
          </div>
        </div>
      </form>
      {result && (
        <div className="card">
          <div className="card-body">
            <h5 className="card-title">Optimization Results</h5>
            <pre>{JSON.stringify(result, null, 2)}</pre>
          </div>
        </div>
      )}
    </div>
  );
}

export default App;
