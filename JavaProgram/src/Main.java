import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args){

        Observer observe = new Observer();
        ArrayList<Restaurants> restaurantsList = new ArrayList<>(); //stores restaurants objects
        ArrayList<Item> itemList = new ArrayList<>(); //used to store the list of the restaurants' menu items and also used
        //to store the list of items being ordered

        Restaurants restaurantObject;
        Item itemObject;

        String token;
        String restaurantName;
        String service;
        String itemname;
        int restaurantIndex;
        double price;

        if(args.length<1){  //checks if an argument was passed in the command line
            //if there is no argument output a message and exit
            System.out.println("Error! No file was passed in the command line");
            System.exit(1);
        }

        try {
            Scanner scanner = new Scanner(new FileInputStream(args[0]));

            while (scanner.hasNext()) {
                token = scanner.next();

                if(token.equals("BeginRestaurant")){
                    //ASSUMING THAT THE COMMANDS ARE GIVEN IN THE ORDER FOUND IN THE ASSIGNMENT SPECIFICATION

                    restaurantName = scanner.next();  //get restaurant name from text file
                    service = scanner.next();         //takeaway, delivery or both?
                    token = scanner.next();           //command has to be 'Item'

                    do{
                        itemname= scanner.next();     //after command Item, there has to be the name
                        price = scanner.nextDouble(); //followed by the price
                        itemObject = new Item(itemname,price);
                        itemList.add(itemObject);
                        token = scanner.next();

                        //itemObject = new Item(itemname, price); //create an object for the item
                        //itemList.add(itemObject);   //add item to an Array list of items
                    }while(token.equals("Item"));   //If command is 'Item' iterate again else it is 'EndRestaurant'

                    restaurantObject = new Restaurants(restaurantName, service, itemList); //create an object for the restaurant
                    restaurantsList.add(restaurantObject);  //add object to the restaurant array list

                }
                itemList.clear(); //clear list to be able to start a new one for a new Restaurants Object

                if(token.equals("BeginOrderList")){
                    //ASSUMING THAT THE COMMANDS ARE GIVEN IN THE ORDER FOUND IN THE ASSIGNMENT SPECIFICATION

                    token = scanner.next();     //has to be 'BeginOrder'

                    restaurantIndex = startingNewOrder(restaurantsList, scanner);
                    service = scanner.next();     //has to be method to be served by
                    token = scanner.next();       //has to be 'OrderItem' command
                    if(restaurantIndex < 0){
                        System.out.println("Please make sure the information in the text file is correct!");
                    }else {
                        collectOrderItems(restaurantsList, itemList, restaurantIndex, service, scanner);
                    }
                }
            }

            observe.calculateHighestRevenue(restaurantsList);
        }catch(FileNotFoundException f){
            System.out.println("File could not be found!");
        }
    }

    private static int searchRestaurant(ArrayList<Restaurants>restaurantsListIn, String nameIn){
        int indexFound = -1;
        for(int i = 0; i<restaurantsListIn.size(); i++){
            if (nameIn.equals(restaurantsListIn.get(i).getName())){
                indexFound = i;
            }
        }
        return indexFound;
    }

    private static int searchItem(ArrayList<Restaurants>restaurantsListIn, int indexFound, String itemName){
        boolean flag =false;
        int i=0;
        int itemIndexFound= -1;
        do{
            if (itemName.equals(restaurantsListIn.get(indexFound).getItemList().get(i).getName())){
                itemIndexFound = i;
                flag = true;
            }
            i++;
        }while(!flag);
        return itemIndexFound;
    }

    private static int startingNewOrder( ArrayList<Restaurants> restaurantsList, Scanner scanner)
    {
        String restaurantName;
        restaurantName = scanner.next();     //has to be restaurant name

        int restaurantIndex = searchRestaurant(restaurantsList, restaurantName); //gets index where the restaurant is stored
        if(restaurantIndex ==-1){
            System.out.println("Restaurant name cannot be found!");}

        return restaurantIndex;
    }

    private static void collectOrderItems( ArrayList<Restaurants>restaurantsList, ArrayList<Item>itemList, int restaurantIndex, String service, Scanner scanner){

        Item itemObject;
        Order orderObject;

        myLinkedList linkedList = new myLinkedList();
        Observer observe = new Observer();

        String token;
        String restaurantName = restaurantsList.get(restaurantIndex).getName();
        String itemname;
        int itemIndex ;
        double price=0.0;
        double totalOrderPrice;


        do{
            itemname = scanner.next();  //has to be item name
            try {
                itemIndex = searchItem(restaurantsList, restaurantIndex, itemname); //gets index where the item is stored
                price = restaurantsList.get(restaurantIndex).getItemList().get(itemIndex).getPrice();  //get the price of the item
            }catch (IndexOutOfBoundsException a){
                System.out.println("The item: "+itemname+" is not offered by "+restaurantsList.get(restaurantIndex).getName());
            }
            totalOrderPrice = observe.calculateTotalOrderPrice(price);
            //totalOrderPrice = totalOrderPrice + price;  //calculating total order price with each loop
            itemObject = new Item(itemname, price); //create an object for the item
            itemList.add(itemObject);   //add item to an Array list of items

            token = scanner.next(); //either another 'OrderItem' command or a 'EndOrder' command

            if(token.equals("EndOrder")) {   //if it is not an Order item but the order is ended take the next input
                token = scanner.next();     //either 'BeginOrder' command or 'EndOrderList'
            }
        }while(token.equals("OrderItem"));  //checks if the last read command is another OrderItem if not exit loop


        restaurantsList.get(restaurantIndex).setRevenue(totalOrderPrice);

        orderObject = new Order(restaurantName, service, itemList, totalOrderPrice); //create an object for the order
        linkedList.add(orderObject);

        itemList.clear(); //clear list to be able to start a new one for a new Restaurants Object

        if(token.equals("BeginOrder")){
            restaurantIndex = startingNewOrder(restaurantsList, scanner);
            service = scanner.next();     //has to be method to be served by
            token = scanner.next();       //has to be 'OrderItem' command
            if(restaurantIndex < 0){
                System.out.println("Please make sure the information in the text file is correct!");
            }else {
                collectOrderItems(restaurantsList, itemList, restaurantIndex, service, scanner);
            }
        }
        linkedList.writeAll();
    }
}
