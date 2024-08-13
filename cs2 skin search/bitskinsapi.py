import requests
import json

auth_key = '5892e375fe9cef844cbf68ed2fcc179991665f982102b38c53c57dee1ea311b9'
def getName(name, lim=1, offs=0, discountLow=0, discountHigh=100):
    data = {
        "limit": lim,
        "offset": offs,
        # "order": [
        #     {'field': 'price', 'order': 'ASC'}
        # ],
        "where": {
            "price_from": 10000,
            "price_to": 50000,
            # "skin_name": f"%{name}%",
            "tradehold_to": 1,
            "discount_from": discountLow,
            "discount_to": discountHigh,
        }
    }

    headers = {'x-apikey': auth_key}
    res = requests.post('https://api.bitskins.com/market/search/730', headers=headers, json=data)
    response = json.loads(res.text)
    out = []
    
    for item in response['list']:
        out.append([item['name'], item['skin_id'], item['price']])
    return out

def getMinSellBitskins(name):
    data = {
        "limit": 1,
        # "skin_id": 5503,
        "order": [
            {'field': 'price', 'order': 'ASC'}
        ],
        "where": {
            "skin_name": name,
            "discount_from": 0,
            "discount_to": 100,
            
        }
    }

    headers = {'x-apikey': auth_key}
    res = requests.post('https://api.bitskins.com/market/search/730', headers=headers, json=data)
    response = json.loads(res.text)
    print(response)
    if response.get('list', None) == None or response.get('list', None)==[]:
        return None
    return response.get('list', None)[0].get('price', None)/1000
    # prices = [x['price_avg'] for x in response]
    # if len(prices) == 0:
    #     return None
    # return sum(prices)/len(prices)/1000

def getMedianSellBitskins(id):
    data = {
        "app_id": 730,
        "skin_id": id,
        "date_from": "2024-01-01",
        "date_to": "2024-07-17"
    }
    headers = {'x-apikey': auth_key}
    res = requests.post('https://api.bitskins.com/market/pricing/summary', headers=headers, json=data)
    response = json.loads(res.text)
    prices = [x['price_avg'] for x in response]
    prices.sort()
    if len(prices)==0:
        return None
    return prices[len(prices)//2]/1000

# print(getMedianSellBitskins(6785))
# print(getMinSellBitskins(5503))
