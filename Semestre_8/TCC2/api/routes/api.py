from flask import Blueprint
from models.Stock import Stock

application = Blueprint('api', __name__, template_folder='templates')

@application.route('/api/stock/<stock>/<period>')
def get(stock, period):
    print(stock, period)
    stock = Stock(stock, period)
    return stock.getDF().to_json()