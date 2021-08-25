/*
 * Helpers
 */
String add_order_to_line(int new_order){
  String message;
  //get orders count
  if (currentOrders<10){
      Serial.println("New order");
      Serial.println(order_id);
      order_ids[currentOrders]=order_id;
      order[currentOrders]=new_order;
      order_status[currentOrders]=false;
      order_id++;
      currentOrders++;
    message="Your order number" + order_ids[currentOrders];
  }else{
    message="Too many orders, try later";
  }
  Serial.println(message);
  return message;
}

void make(){
  int coctail[]={30,50,100};
  currentOrders--;
  is_ready=false;
  delay(2000);
  is_ready=true;
}
