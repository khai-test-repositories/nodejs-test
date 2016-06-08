#! /usr/env/bin node

var {alert, getCompilerName} = require('.');
alert("NodeJS C++ addon", `Using compiler ${getCompilerName()}`);
