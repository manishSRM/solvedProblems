import re
import os
import sqlite3 as lite
import sys
import argparse

class UrlShort:

    def __init__(self):
        self.con = lite.connect('test.db')
        self.cur = self.con.cursor()
        self.myStr = "abcdefghijklmnopqrstuvwxyzABCDEFGHJIKLMNOPQRSTUVWXYZ0123456789"
        self.prefix = "http://example.com/"
        self.myDict = {}
        i = 0
        for char in self.myStr:
            self.myDict[char] = i
            i = i + 1

    def setup_db(self):
        self.cur.execute('CREATE TABLE IF NOT EXISTS Url(ID INTEGER PRIMARY KEY AUTOINCREMENT, URLNAME TEXT)')

    def convert_to_base62(self, id):
        hashStr = ''
        while id:
            rem = id % 62
            id = id / 62
            hashStr = hashStr + self.myStr[rem]
        return hashStr

    def convert_to_base10(self, hashStr):
        id = 0
        prev = 1
        for char in hashStr:
            id = id + (self.myDict[char] * prev)
            prev = prev * 62
        return id

    def long_to_short(self, url):
        newRow = (url,)
        self.cur.execute('INSERT INTO Url(URLNAME) VALUES(?)', newRow)
        id = self.cur.lastrowid
        self.con.commit()
        hashStr = self.convert_to_base62(id)
        return self.prefix + hashStr

    def short_to_long(self, url):
        hashStr = ""
        if url.startswith(self.prefix):
            hashStr = url[len(self.prefix):]
        uId = self.convert_to_base10(hashStr)
        self.cur.execute('SELECT URLNAME FROM Url Where ID =:id', {"id": uId})
        row = self.cur.fetchone()
        return row

    def showTable(self):
        for row in self.cur.execute('SELECT * FROM Url'):
            print(row)


def main():
    parser = argparse.ArgumentParser(description="Shortens a given URL and vice versa")
    parser.add_argument("url", help="url to shorten or to long")
    parser.add_argument("-l", "--tolong", help="flag for specify conversion from short to long", action="store_true")
    parser.add_argument("-s", "--showtable", help="show the current data in table", action="store_true")
    args = parser.parse_args()
    obj = UrlShort()
    obj.setup_db()
    if args.tolong:
        decodedUrl = obj.short_to_long(args.url)
        print(decodedUrl)
    else:
        encodedUrl =  obj.long_to_short(args.url)
        print(encodedUrl)
    if args.showtable:
        obj.showTable();

if __name__ == "__main__":
    main()
# python urlshort.py [--tolong] <>
# python urlshort.py <>

