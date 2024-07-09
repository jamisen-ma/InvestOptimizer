import React, { useState } from 'react';
import axios from 'axios';

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
    <div className="App">
      <h1>Portfolio Optimizer</h1>
      <form onSubmit={handleSubmit}>
        {portfolio.map((entry, index) => (
          <div key={index}>
            <input
              type="text"
              name="ticker"
              placeholder="Ticker"
              value={entry.ticker}
              onChange={(e) => handleChange(index, e)}
            />
            <input
              type="number"
              name="amount"
              placeholder="Amount"
              value={entry.amount}
              onChange={(e) => handleChange(index, e)}
            />
          </div>
        ))}
        <button type="button" onClick={handleAdd}>Add Stock</button>
        <button type="submit">Optimize Portfolio</button>
      </form>
      {result && (
        <div>
          <h2>Optimization Results</h2>
          <pre>{JSON.stringify(result, null, 2)}</pre>
        </div>
      )}
    </div>
  );
}

export default App;
