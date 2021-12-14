# Simple Compiler

```c
int main() {
    int a = 10;
    a = a + 10; // hello world!
    /*
        hello world!
    */
    return 0;
}
```

Result of compiler after lexing:
```
identifier: int
identifier: main
operator: (
operator: )
operator: {
identifier: int
identifier: a
operator: =
decimal: 10
operator: ;
identifier: a
operator: =
identifier: a
operator: +
decimal: 10
operator: ;
comment: // hello world!
multiline comment:
/*
        hello world!
    */
identifier: return
oct: 0
operator: ;
operator: }
```