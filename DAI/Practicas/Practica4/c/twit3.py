#!/usr/bin/python

# En este ejemplo muestro el estado de usuarios y amigos

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
for tweets in x.home_timeline(count=2): # esta funcion es la que nos permite mostrar el estado de mis amigos
    print(tweets.created_at)
    print(tweets.user.screen_name) # nos da informacion sobre el usuario del tweet
    print(tweets.text)
    print(' *'*40)
