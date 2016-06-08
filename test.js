#! /usr/env/bin node

var {alert, getCompilerCode} = require('.');
alert("NodeJS C++ addon", `Using compiler ${getCompilerCode()}`);
