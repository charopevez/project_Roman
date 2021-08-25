// ************************ Client pages *************************************
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
  <title>Welcome page</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  </head><body>
  <h3>Welcome page</h3>
  <br><br>
  <form action="/order">
    <br>
    Coctail: 
    <select name = "coctail">
      <option value=1>White Russian</option>
      <option value=3>B52</option>
      <option value=10>Mohito</option>
    </select>
    <br>
    Amount: 
    <select name = "amount">
      <option value=1>1</option>
      <option value=2>2</option>
      <option value=3>3</option>
    </select>
    <input type="submit" value="Submit">
  </form>
</body></html>)rawliteral";
