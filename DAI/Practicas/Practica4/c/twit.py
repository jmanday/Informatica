#!/usr/bin/python

# En este ejemplo cambio mi estado en twitter

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
x.update_status('@j_manday Si me Funciono')
