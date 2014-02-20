#!/usr/bin/python

# En este ejemplo realizo una busqueda de contenido

import tweepy

# Colocamos las claves
CONSUMER_KEY = 'h4bXmMd17UrqoTCnAu9v5g'
CONSUMER_SECRET = 'FfjY1x6JrLnReNxQBEt7KDJxsSiBvVpYkKp6JZIH4'
ACCESS_KEY = '2162658013-rrgTdJPcyK87TH41vHiZhjLSkDucNd2Sesku1ip'
ACCESS_SECRET = 'VZJZcxjWxkxjH6rmY2JqLeWAsj5OquLTMS7hO3K5xjFgT'

#En esta parte nos identifica para poder realizar operaciones
auth = tweepy.OAuthHandler(CONSUMER_KEY, CONSUMER_SECRET)
auth.set_access_token(ACCESS_KEY, ACCESS_SECRET)


x = tweepy.API(auth)
for tweets in x.search(q='balondeoro',count=4, result_type='recent'): # funcion de busqueda (le decimos que nos busque resultados recientes) 
    print(tweets.created_at)
    print(tweets.user.screen_name)
    print(tweets.text)
    print(' *'*40)
