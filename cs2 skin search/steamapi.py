from datetime import datetime
import json
import steammarket as sm
import requests
key = "kELNnfne3NNzjbarzpc8D-NHlg8"
def getPrice(name):
    item = requests.get(f"https://api.steamapis.com/market/item/730/{name}?api_key={key}")
    # item = sm.get_csgo_item(name, currency='USD')
    # print(item.content)
    try:
        d = json.loads(item.content.decode('utf-8'))
    
    except:
        return None
    
    
    # d = dict(toks.split(":") for toks in item.content.split(",") if toks)
    if d.get('error', None)!=None:
        return None
    prices = [x[1] for x in d.get('median_avg_prices_15days')]
    if len(prices)==0:
        return None
    return sum(prices)/len(prices)

def getMinSellSteam(name):
    item = requests.get(f"https://api.steamapis.com/market/item/730/{name}?api_key={key}")
    # item = sm.get_csgo_item(name, currency='USD')
    # print(item.content)
    try:
        d = json.loads(item.content.decode('utf-8'))
    
    except:
        return None
    
    
    # d = dict(toks.split(":") for toks in item.content.split(",") if toks)
    if d.get('error', None)!=None:
        return None
    histo = d.get("histogram", -1)
    selling = histo.get('sell_order_array', -1)
    ordered = sorted(selling, key=lambda x: x['price'])
    return ordered[0]['price']

# print(getMinSellSteam("★ Bowie Knife | Black Laminate (Well-Worn)"))