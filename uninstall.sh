#!/bin/bash

systemctl disable ic_recorder.*
rm -f /lib/systemd/system/ic_recorder.*
systemctl daemon-reload
