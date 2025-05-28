# Laboration 3

### Uppgift 1
För att fixa uppgift 1 så följde först och främst intrukstionerna. För att förstå .gitignore lite mer så googlade jag och det jag nu ha rlagt till i den filen är att den ska strunta i html mappen.
Sedan skapade jag README.md genom att skriva "touch README.md". 
Jag körde sedan Doxyn i mappen Docs för att skapa html-mappen osv. men jag tycker att jag har väldigt lite förståelse över vad som sker i just den här labben. Speciellt doxygen, där hänger jag inte med lika mycket men fick till de filer som skulle vara med.
Sedan skapade jag CMakelists "touch CMakeslists.txt" där jag sedan öppnade hela mappen i CLion för att konfiguera CMake.

### Uppgift 2
För att klara uppgift 2 så började med att googla runt gällande stack där man använder länkade listor för insperation. Hittade många olika varianter men anpassade min för just testet.Är fortfarande osäker på om koden och CMake verkligen stämmer men får se när feedback kommer. Det funkade i alla fall för mig. Upggiften var ganska svår eftersom det var ett tag sedan man skrev egna, korta C++ koder.Jag valde förövrigt att bara skriva om stack.h, jag la ej till en annan fil. 
### Uppgift 3
Det tog ganska lång tid för mig att klara av just uppgift 3 eftersom den var lite klurig men till slut fick jag till det och började förstå hur koden skulle skrivas. Jag använde mig av då av "SCENARIO / GIVEN / WHEN / THEN" som kan ses längre ner. Jag googlade för att hitta exempel på andra typer av tests. Sedan la jag även till mer filer för .gitignore. Gjorde också om CMakelist så att 3 olika build kan användas. Sedan för att skicka in arbetet så körs bara commit och sedan push. 
Överlag tycker jag att den här biten var den svåraste eftersom det kändes mycket mer nytt.
```cpp
SCENARIO("Using valid strings") {
    GIVEN("Valid strings testing the main 4 operands") {
        string expression_1 = "3+7";
        string expression_2 = "15-4";
        string expression_3 = "(3*6)*7";
        string expression_4 = "(6*2)/(3+6)";
        WHEN("4 objects are given correct expressions") {
            MathExpression m_1(expression_1);
            MathExpression m_2(expression_2);
            MathExpression m_3(expression_3);
            MathExpression m_4(expression_4);

            // Valid
            THEN("m_1 should return valid"){
                REQUIRE(m_1.isValid());
            }
            THEN("m_2 should return valid"){
                REQUIRE(m_2.isValid());
            } // osv
```

##### Uppdatering
Jag har nu lagt till ```set (CMAKE_CXX_STANDARD 11)```, sedan kollade jag hur test/bug kunde användas och förstod att de skulle skrivs i MathExpression.h. Jag har även ändrat output i Doxyfile till endast "Docs" eftersom det tidigare angav en specifik väg. Jag hoppas att jag fick med allt som behövdes. 
    