#!/bin/bash

make
cp ./ic_recorder /usr/bin/
cp ./ic_recorder.path /lib/systemd/system/
cp ./ic_recorder.service /lib/systemd/system/
systemctl daemon-reload
systemctl enable ic_recorder.path
systemctl enable ic_recorder
