from flask import Flask, request, jsonify
from flask_restful import Resource, Api
from sqlalchemy import create_engine
from routes.api import application

app = Flask(__name__)
api = Api(app)

app.register_blueprint(application)

# http://127.0.0.1:5000/stock/USDBRL=X/30

if __name__ == '__main__':
  app.run()