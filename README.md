# expresion_tree
This is a private project(C language). Using enums and unions to produce polymorphism on the nodes of an expression tree.

This is a reimplementation of the bc binary. It is a calculator that performs only with integers though.
symbols authorized are: *, -, /, ^, +, (, ) and numbers 0-9.

Like bc, it will return a "parser error" message if the character combinaison is not allowed example: "2 ** 3".

The technique used is as follow:
1) Tokenisation (linked list).
2) Parsing and Conversion of the infix equation into a postfix equation(reverse polish notation)
3) The linked list that is now in a rpn order. is tuned into a binary expression tree.
4) calculate result from the given root of the binary expression tree.
