import java.util.Scanner;
import java.util.Scanner;

class details_node{
	String food_name;
	double food_price;
	int food_quantity;
	details_node next;
	details_node prev;
	
	details_node(String f,double p,int q)
	{
		food_name = f;
		food_price = p;
		food_quantity = q;
		next = null;
		prev = null;
	}
}
class Resto{
	details_node head;
	
	Scanner sc=new Scanner(System.in);
	
	void create_food_list(String f_name,double f_price,int f_q)		//create a list of food
	{
		details_node ptr = null;
		details_node nn=new details_node(f_name,f_price,f_q);
		if(head==null)
		{
			head=nn;
			return;
		}else {
			ptr=head;
			while(ptr.next!=null)
			{
				ptr=ptr.next;
			}
			ptr.next = nn;
			nn.prev = ptr;
		}	
	}
	void display_food_list()
	{
		details_node ptr = null;
		if(head==null)
		{
			System.out.println("Please create food menu to display");
		}else {
			ptr=head;
			System.out.println("Menu \t\t Price \t\t Quantity");
			while(ptr!=null)
			{
				System.out.println(ptr.food_name+" \t\t "+ptr.food_price+" \t\t "+ptr.food_quantity);
				ptr=ptr.next;
			}
			System.out.println("--------------------------------------------");
		}
		
	}
}
public class Main {
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("---------------------Welcome to Paprika Veg Cuisine-----------------");
		Resto person = new Resto();

		int ch;
		int k=0;
		
		do
		{
			System.out.println("1:Create food list");
			System.out.println("2:Display food list");
		
			ch=sc.nextInt();
			switch(ch)
			{
				case 1:
					String food;
					double price;
					int quantity;
					System.out.println("Enter food:");
					food = sc.next();
					System.out.println("Enter price:");
					price = sc.nextInt();
					System.out.println("Enter quantity:");
					quantity = sc.nextInt();
					person.create_food_list(food, price, quantity);
					
					break;
				case 2:
					person.display_food_list();
					break;
				
				default:
					System.out.println("Please enter a valid choice:");
			}
			System.out.println("Enter 1 to repeat 0 to stop:");
			k=sc.nextInt();
		}while(k==1);
}
}
