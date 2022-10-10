from flask import Flask, request, jsonify
from flask_restful import Resource, Api
from sqlalchemy import create_engine
from json import dumps
from routes.Stock import Stock

app = Flask(__name__)
api = Api(app)

api.add_resource(Stock, '/stock/<stock>/<period>') # http://127.0.0.1:5000/stock/USDBRL=X/30

if __name__ == '__main__':
  app.run()