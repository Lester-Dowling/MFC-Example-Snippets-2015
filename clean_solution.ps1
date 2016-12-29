# Clean build artifacts within the directory of this script.

Write-Host "Executing script $PSCommandPath"
Write-Host "Cleaning build artifacts in directory $PSScriptRoot"

Get-ChildItem -Directory "$PSScriptRoot"          | where Name -eq "ipch"           | Remove-Item -Force -Recurse
Get-ChildItem "$PSScriptRoot"                     | where Name -Match ".VC.db$"     | Remove-Item
Get-ChildItem -Recurse "$PSScriptRoot"            | where Name -Match ".aps$"       | Remove-Item
Get-ChildItem -Recurse -Directory "$PSScriptRoot" | where Name -eq "x64"            | Remove-Item -Force -Recurse
