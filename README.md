# JsonOperations
files used for json operations such as write, parsing, reading

This functions is faster in terms of operations as it is used to form json strings without sprintf statments
1. Format switch is available so that the json string is formed using tab spaces, newline character for PRETTY format else it is formed in single buffer in a contiguous manner
2. The intention is to allow it the function to be safely used in 32 bit MCU with limited safe string operation function available.
3. These files are written in Codeblocks thus can be opened as project and tested using the code written in JSON_Test.c
4. value searching and parsing is done using hash value calculations, thus faster searching can be done if the json string is formed using the Writer.
