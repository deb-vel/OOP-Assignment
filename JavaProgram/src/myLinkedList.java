import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

class myLinkedList {

    private ListNode head; //variable of type ListNode points to the head of the list
    private int sizeOfList;

    myLinkedList() {
        head = null; //point the linked list head to null
        sizeOfList = 0;
    }

    public void add(Order newOrder) { //adds objects of type Order into the linked list
        ListNode newNode = new ListNode(newOrder); //the new node to store the order to be added
        if (head == null) {
            head = newNode;  //if there is no node in the linked list yet, create the first one
        } else {
            ListNode temp = head; //else start from the head node of the list
            while (temp.next != null) { //while the linked list is not fully traversed
                temp = temp.next; //set temp to the next node of the linked list
            }
            temp.next = newNode; //creates the last node of the list after temp.next reaches null
        }
        sizeOfList++;
    }

    public void writeAll() { //this writes all orders stored in the linked list to the file called Orders.txt

        if (head != null) { //checks if there is anything inside the list
            ListNode temp = head; //starting from the first node
            try {
                Writer wr = new FileWriter("Orders.txt", true); //create or open file Orders.txt
                do {
                    wr.write("---NEW ORDER---\n" + temp.order.getRestaurantName() + "\t"); //writes restaurant name
                    wr.write(temp.order.getService() + "\nOrdered Items:"); //writes mode of service

                    for (Item item : temp.order.getItemList()) { //loops through the whole Arraylist which contains ordered items
                        wr.write(item.getName() + "\t");  //writes name of food
                        wr.write(item.getPrice() + "euros\n");//writes price of food
                    }

                    wr.write("Total Order Price" + temp.order.getTotalOrderPrice() + "\n\n"); //writes the total price of the order

                    temp = temp.next; //move to the next node
                } while (temp != null); //continue looping until temp reaches null

                wr.flush();
                wr.close(); //closing file

            } catch (IOException e) {
                System.out.println("There was a problem in opening or creating the file!");
            }
        }
    }
}

