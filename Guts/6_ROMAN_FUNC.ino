/*
 * Helpers
 */
String add_order_to_line(int new_order){
  String message;
  //get orders count
  if (currentOrders<10){
      Serial.printf("New order [%d]\n", order_id );
      order_ids[currentOrders]=order_id;
      order[currentOrders]=new_order;
      order_status[currentOrders]=false;
      order_id++;
      currentOrders++;
      order_start_time= millis();
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
  Serial.printf("Start making an order [%d]\n", order_ids[0]);
  Serial.printf("End making an order [%d]\n", order_ids[0]);
  is_ready=true;
}
