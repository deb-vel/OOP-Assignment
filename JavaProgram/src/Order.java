import java.io.*;
import java.util.ArrayList;

public class Order implements Serializable { //inherits the restaurants' variables

    private double totalOrderPrice;
    private String restaurantName;
    private String service;
    private ArrayList<Item> itemList = new ArrayList<>();

    public Order(String restaurantNameIn, String serviceIn, ArrayList<Item> itemListIn, double totalOrderPriceIn){
        totalOrderPrice = totalOrderPriceIn;
        restaurantName = restaurantNameIn;
        service = serviceIn;
        itemList.addAll(itemListIn);
    }

    public void setRestaurantName(String restaurantName) {
        this.restaurantName = restaurantName;
    }

    public void setOrderList(ArrayList<Item> orderListIn) {
        ArrayList<Item> orderList = new ArrayList<>(orderListIn);
    }

    public void setService(String service) {
        this.service = service;
    }

    public void setTotalOrderPrice(double totalOrderPrice) {
        this.totalOrderPrice = totalOrderPrice;
    }

    public String getRestaurantName() {
        return restaurantName;
    }

    public double getTotalOrderPrice() {
        return totalOrderPrice;
    }

    public String getService() {
        return service;
    }

    public ArrayList<Item> getItemList() {
        return itemList;
    }
}