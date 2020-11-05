import java.io.*;
import java.util.ArrayList;

public class Restaurants implements Serializable{
    private String name;
    private String methodOfServing;
    private ArrayList<Item> itemList = new ArrayList<>();
    private double revenue = 0.0;

    public Restaurants(String nameIn, String methodOfServingIn, ArrayList<Item>itemListIn){
        name = nameIn;
        methodOfServing = methodOfServingIn;
        itemList.addAll(itemListIn);
    }

    //getters
    public String getName(){
        return name;
    }

    public double getRevenue() {
        return revenue;
    }

    public ArrayList<Item> getItemList() {
        return itemList;
    }

    public void setItemList(ArrayList<Item> itemListIn) {
        ArrayList<Item> itemList = new ArrayList<Item>(itemListIn);
    }

    public String getMethodOfServing(){
        return methodOfServing;
    }


    //setters
    public void setName(String nameIn){
        name = nameIn;
    }

    public void setRevenue(double revenueIn) {
        revenue = revenue + revenueIn;
    }

    public void setMethodOfServing(String methodOfServingIn) {
        methodOfServing = methodOfServingIn;
    }

}
