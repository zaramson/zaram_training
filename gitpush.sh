#!/usr/bin/expect

set timeout -1

spwan git add .; git commit -m 'comment'; git push -u origin +master
expect "Username for 'https://github.com':"
#send "zaram_training\r"

#expect "Password for 'https://zaram_training@github.com':"
#send "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\r"

interact
