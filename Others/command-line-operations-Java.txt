//Program to demonstrate the use of command line for programs in Java

import java.util.*;

public class Average
{
	public static void main(String args[])
	{
		//Check if the command line arguments provided is empty or not
		if(args.length == 0)
			System.out.println("No arguments given in the command line");
		else
		{
			int sum = 0;

			//Looping through the array of numbers provided in the command line
			for(int i=0;i<args.length;i++)
				sum+=Integer.parseInt(args[i]);

			//Make sure the average is of float type by explicitly making it of type float
			float avg = (float)sum/args.length;
			System.out.println("Average = "+avg);
		}
	}
}