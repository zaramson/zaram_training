#!/usr/bin/expect

set timeout -1

spawn bash -c gitpush
expect "Username for 'https://github.com':"
#send "zaram_training\r"

#expect "Password for 'https://zaram_training@github.com':"
#send "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\r"

interact
