How the output files are generated

$fpc spartans.pas
$./spartans > spartansOutput.txt
$fpc mergeArrays.pas
$./mergeArrays < mergeArraysInput.txt > mergeArraysOutput.txt
$fpc presidents.pas
$./presidents > presidentsOutput.txt

Note that this will all be generated under the root directory for this project.
To clean things up a little I decided to make an ouput directory and move all the output files into there.
This can be achieved as follows (assuming the outfiles already exists)

$mkdir output
$mv *Output* output

Thanks.
