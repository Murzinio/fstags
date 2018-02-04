#!/usr/bin/env bash

$DIR = "cmake_output";
if (!(Test-Path -Path "cmake_output"))
{
    New-Item -ItemType directory -Path $DIR;
}

cd cmake_output

cmake ..