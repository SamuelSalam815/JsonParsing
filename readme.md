### TODO

- Improve and standardize error messages
- Print entire line when error encountered (i.e. even characters not parsed or peeked yet)
- Tidy up public interface
    - Out of the parsing functions, the client only needs to access 'ParseJsonValue'
- Test use of data structures after parsing
    - e.g. index array, or perform look up on json object
- Test parsing on a wider range of inputs