#!/usr/bin/expect

set timeout -1

spawn git add .
expect eof

spawn git commit -m "comment"
expect eof

spawn git push -u origin +master
expect "Username for 'https://github.com':"
#send "zaram_training\r"

#expect "Password for 'https://zaram_training@github.com':"
#send "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\r"

interact
