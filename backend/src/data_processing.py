import pandas as pd
import yfinance as yf

def fetch_and_clean_data(tickers, start='2010-01-01', end='2020-12-31'):
    data = yf.download(tickers, start=start, end=end)['Adj Close']
    data = data.dropna()
    returns = data.pct_change().dropna()
    returns.to_csv('cleaned_data.csv')
    return returns