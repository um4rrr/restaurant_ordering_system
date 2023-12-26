#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
using namespace std;

// HEADER FUNCTIONS
void access(); // umar

void header(); // umar

void payment_summary_header(); // umar

void credit_discount_table_intersection(); // umar

void order_header(); // umar

void credit_discount_table(); // umar

void booking_header(string username, int bookingID, string reservation_date, string meal, int adults, int children, double reservation_cost); // umar

void display_staff_order_header();

// HEADER & PROCESSING FUNCTIONS
void signUp(); // umar 

void login(); // umar 

void staffsignup(); // umar

void stafflogin(); // umar

void staffmainmenu(); // umar

void staff_check_order(); //umar

void remove_order_username_order_txt(); // umar 

void remove_order_customer_id_order_txt(); // umar

void remove_order_username_outstanding_payment_txt(string username); // umar

void update_order_customer_id_order_txt(); // umar

void update_order_username_order_txt(); // umar

void update_order_username_outstanding_payment_txt(string username_input, string order); // umar

void staff_display_orders(); // umar & hong yu

void staff_display_reservations(); // umar

void remove_reservation_username_reservation_list_txt(); // umar

void remove_reservation_username_outstanding_payment_txt(string customer_username_input); // umar

void remove_reservation_customer_id_reservation_list_txt(); // umar

void remove_reservation_customer_id_outstanding_payment_txt(int customer_ID_input); // umar

void staff_display_reservations_header(); // umar

void extended_reservation_company_header(); // umar

void paid_payments_horizontal_line(); // umar

void extended_paid_payments_company_header(); // umar

void display_staff_paid_payments_filter_id(); // umar

void display_staff_paid_payments(); // umar

void extended_paid_payments_company_header(); // umar

void display_staff_paid_payments_filter_username(); // umar

void display_straight_lines(); // umar

double book_reservation_cost(int adults, int children); // umar

bool checkdate(int m, int d, int y); // umar

void book_reservation(); // umar

void mainmenu(); // umar

void cancel_reservation(); // umar

void payment(); // umar

double calculate_total_ingredients_quantity_cost(int quantity, double cost_per_ingredients); // umar

// IMPORTANT GLOBAL VARIABLES
string username;                  // global variable for user's username (to display username)
string staff_username;            // global variable for staff's username (to display staff username)
int staffID;                      // global variable for staff id (to display staff id)
int customerID;                   // global variable for user's id (to display id)
int credits;                      // global variable for user's credits (for computation of discount)
double total_cost = 0;            // global variable for total cost needed to pay (for computation of total cost needed to pay)
double booking_cost = 0;          // global variable for booking cost needed to pay (for computation of total cost needed to pay)
double menu_cost = 0;             // global variable for menu cost needed to pay (for computation of total cost needed to pay)

int main() {
	access();
}

// starting point of program (UMAR)
void access() {
	int choice;
	double price;
	do {
		header();
		cout << "\t\t\tAccess Page" << endl;
		display_straight_lines();
		cout << " 1) Access as Customer" << endl;
		cout << " 2) Access as Staff" << endl;
		cout << "\n Option: ";
		cin >> choice;
		if (choice == 1) {
			system("cls");
			header();
			cout << "\t\tExisting Customer Account" << endl;
			display_straight_lines();
			cout << " Do you have an existing account with us?" << endl;
			cout << " 1. Yes" << endl;
			cout << " 2. No" << endl;
			cout << " 9. Exit Program" << endl;
			cout << " Option: ";
			cin >> choice;
			cout << endl;
			switch (choice) {
			case 1:
				system("cls");
				login(); // login consisting of sign up then after sign up, do while loop
				system("cls");
				mainmenu(); // TAKE NOTE
				break; // breaks switch statement
			case 2:
				system("cls");
				signUp();
				mainmenu();
				break;
			}
		}
		else if (choice == 2) {
			system("cls");
			header();
			cout << "\t\tExisting Staff Account" << endl;
			display_straight_lines();
			cout << " Do you have an existing staff account?" << endl;
			cout << " 1. Yes" << endl;
			cout << " 2. No" << endl;
			cout << " 9. Exit Program" << endl;
			cout << " Option: ";
			cin >> choice;
			cout << endl;
			switch (choice) {
			case 1:
				system("cls");
				stafflogin(); // login consisting of sign up then after sign up, do while loop
				system("cls");
				staffmainmenu();
				//staffmainmenu(); // TAKE NOTE
				break; // breaks switch statement
			case 2:
				staffsignup();
				break;
			}
		}
	} while (choice != 9);
}

// function to display straight lines (UMAR)
void display_straight_lines() {
	char horizontal_lines = 196;
	int breadth = 0;
	while (breadth <= 57) {
		cout << horizontal_lines;
		breadth++;
	}
	breadth = 0;
	cout << endl;
}

// header function to display company's header (UMAR)
void header() {
	char horizontal_lines = 196, vertical_lines = 179, bottom_lh = 192, top_lh = 218, top_rh = 191, bottom_rh = 217;
	int breadth = 0;
	cout << left;
	for (int x = 1; x <= 5; x++) { // breadth
		if (x != 1 && x != 3 && x != 5) {
			cout << setw(57) << vertical_lines << vertical_lines << endl; // middle length (INCLUDING TEXT)
		}
		else if (x == 3) {
			cout << setw(10) << vertical_lines << setw(47) << "Panteleone's Pizza | #1 Pizza in Town!" << vertical_lines << endl;
		}
		else if (x == 1) {
			cout << top_lh;
			while (breadth <= 55) { // top length
				cout << horizontal_lines;
				breadth++;
			}
			cout << top_rh << endl;
			breadth = 0;
		}
		else if (x == 5) { // bottom length
			cout << bottom_lh;
			while (breadth <= 55) {
				cout << horizontal_lines;
				breadth++;
			}
			cout << bottom_rh << endl;
			breadth = 0;
		}
	}
}

// header to display user's booking summary (takes in paramters from global variable and local variables) (UMAR)
void booking_header(string username, int bookingID, string reservation_date, string meal, int adults, int children, double reservation_cost) {
	char horizontal_lines = 196, vertical_lines = 179, right_intersect = 180, left_intersect = 195, bottom_lh = 192, top_lh = 218, top_rh = 191, bottom_rh = 217;
	int breadth = 0;
	cout << left;
	cout << fixed << setprecision(2);
	for (int x = 1; x <= 15; x++) { // breadth
		if (x != 1 && x != 3 && x != 5 && x != 6 && x != 7 && x != 8 && x != 9 && x != 11 && x != 12 && x != 14 && x != 15) {
			cout << setw(32) << vertical_lines << vertical_lines << endl; // adjusts breadth (not within text row)
		}
		else if (x == 3) {
			cout << setw(9) << vertical_lines << setw(23) << "BOOKING SUMMARY" << vertical_lines << endl; // adjust length
		}
		else if (x == 5) {
			cout << left_intersect;
			while (breadth <= 30) {
				cout << horizontal_lines;
				breadth++;
			}
			cout << right_intersect << endl;
			breadth = 0;
		}
		else if (x == 6) {
			cout << setw(2) << vertical_lines << setw(10) << "Username: " << setw(20) << username << vertical_lines << endl;
		}
		else if (x == 7) {
			cout << setw(2) << vertical_lines << setw(12) << "Booking ID: " << setw(18) << bookingID << vertical_lines << endl;
		}
		else if (x == 8) {
			cout << setw(2) << vertical_lines << setw(18) << "Reservation Date: " << setw(12) << reservation_date << vertical_lines << endl;
		}
		else if (x == 9) {
			cout << setw(2) << vertical_lines << setw(6) << "Meal: " << setw(24) << meal << vertical_lines << endl;
		}
		else if (x == 11) {
			cout << setw(2) << vertical_lines << setw(8) << "Adults: " << setw(22) << adults << vertical_lines << endl;
		}
		else if (x == 12) {
			cout << setw(2) << vertical_lines << setw(8) << "Children: " << setw(20) << children << vertical_lines << endl;
		}
		else if (x == 14) {
			cout << setw(2) << vertical_lines << setw(19) << "Reservation Cost: $" << setw(11) << reservation_cost << vertical_lines << endl;
		}
		else if (x == 1) {
			cout << top_lh;
			while (breadth <= 30) { // top length
				cout << horizontal_lines;
				breadth++;
			}
			cout << top_rh << endl;
			breadth = 0;
		}
		else if (x == 15) { // bottom length
			cout << bottom_lh;
			while (breadth <= 30) {
				cout << horizontal_lines;
				breadth++;
			}
			cout << bottom_rh << endl;
			breadth = 0;
		}
	}
}

// header function to display course menu (UMAR)
void order_header() {
	char horizontal_lines = 196, vertical_lines = 179, right_intersect = 180, left_intersect = 195, bottom_lh = 192, top_lh = 218, top_rh = 191, bottom_rh = 217, bullet = 249;
	int breadth = 0;
	cout << left;
	cout << fixed << setprecision(2);
	for (int x = 1; x <= 19; x++) { // breadth
		if (x != 1 && x != 3 && x != 5 && x != 6 && x != 7 && x != 8 && x != 10 && x != 11 && x != 12 && x != 13 && x != 15 && x != 16 && x != 17 && x != 18 && x != 19) {
			cout << setw(32) << vertical_lines << vertical_lines << endl; // adjusts breadth (not within text row)
		}
		else if (x == 3) {
			cout << setw(7) << vertical_lines << setw(25) << "3 Course Meal ($69)" << vertical_lines << endl; // adjust length
		}
		else if (x == 5) {
			cout << left_intersect;
			while (breadth <= 30) {
				cout << horizontal_lines;
				breadth++;
			}
			cout << right_intersect << endl;
			breadth = 0;
		}
		else if (x == 6) {
			cout << setw(2) << vertical_lines << setw(30) << "Starters" << vertical_lines << endl;
		}
		else if (x == 7) {
			cout << setw(2) << vertical_lines << bullet << setw(29) << " Chicken Soup" << vertical_lines << endl;
		}
		else if (x == 8) {
			cout << setw(2) << vertical_lines << bullet << setw(29) << " Garlic Bread With Cheese" << vertical_lines << endl;
		}
		else if (x == 10) {
			cout << setw(2) << vertical_lines << setw(30) << "Main Dish" << vertical_lines << endl;
		}
		else if (x == 11) {
			cout << setw(2) << vertical_lines << bullet << setw(29) << " Spaghetti Bolognese" << vertical_lines << endl;
		}
		else if (x == 12) {
			cout << setw(2) << vertical_lines << bullet << setw(29) << " Hawaiian Pizza" << vertical_lines << endl;
		}
		else if (x == 13) {
			cout << setw(2) << vertical_lines << bullet << setw(29) << " Classic Pepperonni Pizza" << vertical_lines << endl;
		}
		else if (x == 15) {
			cout << setw(2) << vertical_lines << setw(30) << "Desserts" << vertical_lines << endl;
		}
		else if (x == 16) {
			cout << setw(2) << vertical_lines << bullet << setw(29) << " Ice Cream" << vertical_lines << endl;
		}
		else if (x == 17) {
			cout << setw(2) << vertical_lines << bullet << setw(29) << " Coffee" << vertical_lines << endl;
		}
		else if (x == 18) {
			cout << setw(2) << vertical_lines << bullet << setw(29) << " Tea" << vertical_lines << endl;
		}
		else if (x == 1) {
			cout << top_lh;
			while (breadth <= 30) { // top length
				cout << horizontal_lines;
				breadth++;
			}
			cout << top_rh << endl;
			breadth = 0;
		}
		else if (x == 19) { // bottom length
			cout << bottom_lh;
			while (breadth <= 30) {
				cout << horizontal_lines;
				breadth++;
			}
			cout << bottom_rh << endl;
			breadth = 0;
		}
	}
	for (int x = 1; x <= 25; x++) { // breadth
		if (x != 1 && x != 3 && x != 5 && x != 6 && x != 7 && x != 8 && x != 10 && x != 11 && x != 12 && x != 13 && x != 15 && x != 16 && x != 17 && x != 18 && x != 20 && x != 21 && x != 22 && x != 23 && x != 23 && x != 25) {
			cout << setw(32) << vertical_lines << vertical_lines << endl; // adjusts breadth (not within text row)
		}
		else if (x == 3) {
			cout << setw(7) << vertical_lines << setw(25) << "4 Course Meal ($99)" << vertical_lines << endl; // adjust length
		}
		else if (x == 5) {
			cout << left_intersect;
			while (breadth <= 30) {
				cout << horizontal_lines;
				breadth++;
			}
			cout << right_intersect << endl;
			breadth = 0;
		}
		else if (x == 6) {
			cout << setw(2) << vertical_lines << setw(30) << "Starters" << vertical_lines << endl;
		}
		else if (x == 7) {
			cout << setw(2) << vertical_lines << bullet << setw(29) << " Chicken Soup" << vertical_lines << endl;
		}
		else if (x == 8) {
			cout << setw(2) << vertical_lines << bullet << setw(29) << " Garlic Bread With Cheese" << vertical_lines << endl;
		}
		else if (x == 10) {
			cout << setw(2) << vertical_lines << setw(30) << "Main Dish" << vertical_lines << endl;
		}
		else if (x == 11) {
			cout << setw(2) << vertical_lines << bullet << setw(29) << " Truffle Pizza" << vertical_lines << endl;
		}
		else if (x == 12) {
			cout << setw(2) << vertical_lines << bullet << setw(29) << " Alfredo Prawn" << vertical_lines << endl;
		}
		else if (x == 13) {
			cout << setw(2) << vertical_lines << bullet << setw(29) << " Portofino Pizza" << vertical_lines << endl;
		}
		else if (x == 15) {
			cout << setw(2) << vertical_lines << setw(30) << "Desserts" << vertical_lines << endl;
		}
		else if (x == 16) {
			cout << setw(2) << vertical_lines << bullet << setw(29) << " Ice Cream" << vertical_lines << endl;
		}
		else if (x == 17) {
			cout << setw(2) << vertical_lines << bullet << setw(29) << " Coffee" << vertical_lines << endl;
		}
		else if (x == 18) {
			cout << setw(2) << vertical_lines << bullet << setw(29) << " Tea" << vertical_lines << endl;
		}
		else if (x == 20) {
			cout << setw(2) << vertical_lines << setw(30) << "Salads" << vertical_lines << endl;
		}
		else if (x == 21) {
			cout << setw(2) << vertical_lines << bullet << setw(29) << " Classic Italian Salad" << vertical_lines << endl;
		}
		else if (x == 22) {
			cout << setw(2) << vertical_lines << bullet << setw(29) << " Caesar Salad" << vertical_lines << endl;
		}
		else if (x == 23) {
			cout << setw(2) << vertical_lines << bullet << setw(29) << " Creamy Vegan Pasta Salad" << vertical_lines << endl;
		}
		else if (x == 1) {
			cout << top_lh;
			while (breadth <= 30) { // top length
				cout << horizontal_lines;
				breadth++;
			}
			cout << top_rh << endl;
			breadth = 0;
		}
		else if (x == 25) { // bottom length
			cout << bottom_lh;
			while (breadth <= 30) {
				cout << horizontal_lines;
				breadth++;
			}
			cout << bottom_rh << endl;
			breadth = 0;
		}
	}
}

// sub function of credit_discount_table() (UMAR)
void credit_discount_table_intersection() {
	char horizontal_lines = 196, vertical_lines = 179, right_intersect = 180, left_intersect = 195, bottom_lh = 192, top_lh = 218, top_rh = 191, bottom_rh = 217, center_intersection = 197, middle_topintersection = 194, middle_bottomintersection = 193, bullet = 249;
	int breadth = 0;
	cout << left_intersect;
	while (breadth <= 51) {
		if (breadth == 25) {
			cout << center_intersection;
		}
		else {
			cout << horizontal_lines;
		}
		breadth++;
	}
	cout << right_intersect << endl;
	breadth = 0;
}

// header function to display table (UMAR)
void credit_discount_table() {
	char horizontal_lines = 196, vertical_lines = 179, right_intersect = 180, left_intersect = 195, bottom_lh = 192, top_lh = 218, top_rh = 191, bottom_middleintersect = 193, bottom_rh = 217, center_intersection = 197, middle_topintersection = 194, middle_bottomintersection = 193, bullet = 249;
	int breadth = 0;
	cout << left;
	cout << fixed << setprecision(2);
	for (int x = 1; x <= 18; x++) { // breadth
		if (x != 1 && x != 3 && x != 5 && x != 6 && x != 7 && x != 8 && x != 9 && x != 10 && x != 11 && x != 12 && x != 13 && x != 14 && x != 15 && x != 16 && x != 17 && x != 18) {
			cout << setw(53) << vertical_lines << vertical_lines << endl; // adjusts breadth (not within text row)
		}
		else if (x == 3) {
			cout << setw(15) << vertical_lines << setw(38) << "Credits & Discount Table" << vertical_lines << endl; // adjust length
		}
		else if (x == 5) {
			cout << left_intersect;
			while (breadth <= 51) {
				if (breadth == 25) {
					cout << middle_topintersection;
				}
				else {
					cout << horizontal_lines;
				}
				breadth++;
			}
			cout << right_intersect << endl;
			breadth = 0;
		}
		else if (x == 6) {
			cout << setw(2) << vertical_lines << setw(24) << "Accumulated Credits" << setw(2) << vertical_lines << setw(25) << "Discount Percentage" << vertical_lines << endl;
		}
		else if (x == 7) {
			credit_discount_table_intersection();
		}
		else if (x == 8) {
			cout << setw(2) << vertical_lines << setw(24) << "0 - 50" << setw(2) << vertical_lines << setw(25) << "2 %" << vertical_lines << endl;
		}
		else if (x == 9) {
			credit_discount_table_intersection();
		}
		else if (x == 10) {
			cout << setw(2) << vertical_lines << setw(24) << "51 - 100" << setw(2) << vertical_lines << setw(25) << "4 %" << vertical_lines << endl;
		}
		else if (x == 11) {
			credit_discount_table_intersection();
		}
		else if (x == 12) {
			cout << setw(2) << vertical_lines << setw(24) << "101 - 150" << setw(2) << vertical_lines << setw(25) << "6 %" << vertical_lines << endl;
		}
		else if (x == 13) {
			credit_discount_table_intersection();
		}
		else if (x == 14) {
			cout << setw(2) << vertical_lines << setw(24) << "151 - 200" << setw(2) << vertical_lines << setw(25) << "8 %" << vertical_lines << endl;
		}
		else if (x == 15) {
			credit_discount_table_intersection();
		}
		else if (x == 16) {
			cout << setw(2) << vertical_lines << setw(24) << ">= 201" << setw(2) << vertical_lines << setw(25) << "10 %" << vertical_lines << endl;
		}
		else if (x == 1) {
			cout << top_lh;
			while (breadth <= 51) { // top length
				cout << horizontal_lines;
				breadth++;
			}
			cout << top_rh << endl;
			breadth = 0;
		}
		else if (x == 18) { // bottom length
			cout << bottom_lh;
			while (breadth <= 51) {
				if (breadth == 25) {
					cout << bottom_middleintersect;
				}
				else {
					cout << horizontal_lines;
				}
				breadth++;
			}
			cout << bottom_rh << endl;
			breadth = 0;
		}
	}
}

// header to display user's payment summary (takes in paramters from global variable and local variables) (UMAR)
void payment_summary_header(string username, int customerID, string status, string dateofreservation, string course_ordered, double reservation_cost, double course_price, double subtotal, double discount_cost, double gst, double grand_total) {
	char horizontal_lines = 196, vertical_lines = 179, right_intersect = 180, left_intersect = 195, bottom_lh = 192, top_lh = 218, top_rh = 191, bottom_rh = 217, bullet = 249;
	int breadth = 0;
	cout << left;
	cout << fixed << setprecision(2);
	for (int x = 1; x <= 23; x++) { // breadth
		if (x != 1 && x != 3 && x != 5 && x != 6 && x != 7 && x != 8 && x != 9 && x != 10 && x != 11 && x != 12 && x != 13 && x != 14 && x != 15 && x != 16 && x != 17 && x != 18 && x != 19 && x != 20 && x != 21 && x != 22 && x != 23) {
			cout << setw(60) << vertical_lines << vertical_lines << endl; // adjusts breadth (not within text row)
		}
		else if (x == 3) {
			cout << setw(23) << vertical_lines << setw(37) << "PAYMENT SUMMARY" << vertical_lines << endl; // adjust length
		}
		else if (x == 5) {
			cout << left_intersect;
			while (breadth <= 58) {
				cout << horizontal_lines;
				breadth++;
			}
			cout << right_intersect << endl;
			breadth = 0;
		}
		else if (x == 6) {
			cout << setw(2) << vertical_lines << "Username: " << setw(48) << username << vertical_lines << endl; // NAME PARAMETER
		}
		else if (x == 7) {
			cout << setw(2) << vertical_lines << "Customer ID: " << setw(45) << customerID << vertical_lines << endl; // CUSTOMER ID PARAMETER
		}
		else if (x == 8) {
			cout << setw(2) << vertical_lines << "Status: " << setw(50) << status << vertical_lines << endl;
		}
		else if (x == 9) {
			cout << setw(2) << vertical_lines << "Date: " << setw(52) << dateofreservation << vertical_lines << endl; // DATE OF BOOKING PARAMETER
		}
		else if (x == 10) {
			cout << left_intersect;
			while (breadth <= 58) {
				cout << horizontal_lines;
				breadth++;
			}
			cout << right_intersect << endl;
			breadth = 0;
		}
		else if (x == 11) {
			cout << setw(2) << vertical_lines << setw(35) << "Items Payable" << setw(12) << "Price($)" << setw(11) << "Total($)" << vertical_lines << endl;
		}
		else if (x == 12) {
			cout << left_intersect;
			while (breadth <= 58) {
				cout << horizontal_lines;
				breadth++;
			}
			cout << right_intersect << endl;
			breadth = 0;;
		}
		else if (x == 13) {
			cout << setw(2) << vertical_lines << setw(35) << course_ordered << setw(23) << course_price << vertical_lines << endl; // COURSE ORDERED PARAMETER & COST OF MENU PARAMETER
		}
		else if (x == 15) {
			cout << setw(2) << vertical_lines << setw(35) << "Reservation Fee" << setw(23) << reservation_cost << vertical_lines << endl; // RESERVATION COST PARAMETER
		}
		else if (x == 16) {
			cout << left_intersect;
			while (breadth <= 58) {
				cout << horizontal_lines;
				breadth++;
			}
			cout << right_intersect << endl;
			breadth = 0;;
		}
		else if (x == 17) {
			cout << setw(2) << vertical_lines << setw(47) << "Subtotal" << setw(11) << subtotal << vertical_lines << endl; // SUBTOTAL PARAMETER
		}
		else if (x == 18) {
			cout << setw(2) << vertical_lines << setw(47) << "Discount Applied" << setw(11) << discount_cost << vertical_lines << endl; // DISCOUNT APPLIED PARAMETER
		}
		else if (x == 19) {
			cout << setw(2) << vertical_lines << setw(47) << "7% GST" << setw(11) << gst << vertical_lines << endl; // COST OF GST PARAMETER
		}
		else if (x == 21) {
			cout << left_intersect;
			while (breadth <= 58) {
				cout << horizontal_lines;
				breadth++;
			}
			cout << right_intersect << endl;
			breadth = 0;;
		}
		else if (x == 22) {
			cout << setw(2) << vertical_lines << setw(47) << "Grand Total (Including 7% GST)" << setw(11) << grand_total << vertical_lines << endl; // COST AFTER GST PARAMETER
		}
		else if (x == 1) {
			cout << top_lh;
			while (breadth <= 58) { // top length
				cout << horizontal_lines;
				breadth++;
			}
			cout << top_rh << endl;
			breadth = 0;
		}
		else if (x == 23) { // bottom length
			cout << bottom_lh;
			while (breadth <= 58) {
				cout << horizontal_lines;
				breadth++;
			}
			cout << bottom_rh << endl;
			breadth = 0;
		}
	}
}

// function to allow new customer's to sign up (UMAR)
void signUp()
{
	system("cls");
	header();
	ifstream inFile;
	ifstream inFile2;
	ifstream inFile3;
	ofstream file;
	ofstream ProfileWCredits;
	ofstream OutstandingPayments;
	ofstream outFile2;
	ofstream outFile3;
	string password, username2, password2;
	int customerID2, option, debitcredit_database = 0, debitcreditno = 0;
	bool exist;
	exist = false;
	file.open("login.txt", fstream::app);
	ProfileWCredits.open("profiles.txt", fstream::app);
	OutstandingPayments.open("outstandingpayment.txt", fstream::app);
	if (!file) cout << "An error has occured. Please contact our staff" << endl;
	else
	{
		inFile.open("login.txt"); // resets EOF marker
		cout << "\t\tCreate Customer Account" << endl;
		display_straight_lines();
		cout << " Enter New Username: ";
		cin >> username;
		cout << " Enter New Password: ";
		cin >> password;
		srand(time(NULL));
		customerID = rand() % (20000 - 10000 + 1) + 10000; // generates a random unused customer id
		while (!inFile.eof() && !exist) { // checks whether username is used/unused
			inFile >> customerID2 >> username2 >> password2;
			if (username == username2) {
				display_straight_lines();
				cout << "  Sorry, the username is taken. Please try a new one." << endl;
				display_straight_lines();
				exist = true;
			}
			else if (customerID == customerID2) {
				customerID = rand() % (20000 - 10000 + 1) + 10000; // regenerates a random unused customer id. will keep continue the loop to check if there's still existing ids
			}
		}
		inFile.close();
		if (exist == true) {
			cout << "\n 1) Retry" << endl;
			cout << " 2) Return" << endl;
			cout << " Option: ";
			cin >> option;
			if (option == 1) {
				signUp();
			}
			else if (option == 2) {
				system("cls");
				access();
			}
		}
		else if (exist == false) {
			menu_cost = 0; // sets global variable credit = 0 so that new registered accounts owe nothing.
			booking_cost = 0; // sets global variable credit = 0 so that new registered accounts owe nothing.
			total_cost = 0; // sets global variable credit = 0 so that new registered accounts owe nothing.
			credits = 0; // sets global variable credit = 0 so that new registered accounts starts with 0 credits.
			inFile2.open("profiles.txt");
			outFile3.open("debitcreditcc.txt", fstream::app);
			outFile3 << "\n" << customerID << "\t" << username << "\t" << debitcreditno; // sets newly registered account with no debit / credit card number 
			OutstandingPayments << "\n" << customerID << "\t" << username << "\t" << menu_cost << "\t" << booking_cost << "\t" << total_cost; // data for outstanding payments are stored in outstanding payment.txt
			file << "\n" << customerID << "\t" << username << "\t" << password;
			ProfileWCredits << "\n" << customerID << "\t" << username << "\t" << credits;
			display_straight_lines();
			cout << "\tRegistration Completed! Logging in...\n";
			display_straight_lines();
			OutstandingPayments.close();
			ProfileWCredits.close();
			outFile3.close();
			file.close();
			Sleep(3000);
			system("cls");
		}
	}
}

// function to allow new staff members to sign up (UMAR)
void staffsignup() {
	system("cls");
	header();
	ifstream inFile; // input stream for stafflogin.txt
	ofstream outFile; // output stream for stafflogin.txt
	ofstream outFile2; // output stream for company's otp system
	int option, otp_input, otp;
	int newstaffID, staff_ID_database;
	string staff_username_input, staff_password_input, staffusername_database, staffpassword_database;
	bool exist, otp_success;
	otp_success = false;
	exist = false;
	inFile.open("stafflogin.txt");
	outFile.open("stafflogin.txt", fstream::app);
	if (!(inFile || outFile)) {
		cout << "An error has occurred. Please contact our staff." << endl;
	}
	else {
		display_straight_lines();
		cout << "\t\tCreate Staff Account" << endl;
		display_straight_lines();
		cout << " Enter New Username: ";
		cin >> staff_username_input;
		cout << " Enter New Password: ";
		cin >> staff_password_input;
		srand(time(NULL));
		newstaffID = rand() % (20000 - 10000 + 1) + 10000;
		while (!inFile.eof() && !exist) { // checks whether username is used/unused
			inFile >> staff_ID_database >> staffusername_database >> staffpassword_database;
			if (staff_username_input == staffusername_database) {
				display_straight_lines();
				cout << "   Sorry, the username is taken. Please try a new one." << endl;
				display_straight_lines();
				exist = true;
			}
			else if (newstaffID == staff_ID_database) {
				newstaffID = rand() % (20000 - 10000 + 1) + 10000; // regenerates a random unused customer id. will keep continue the loop to check if there's still existing ids
			}
		}
		if (exist == true) {
			cout << " 1) Retry" << endl;
			cout << " 2) Return" << endl;
			cout << "\n Option: ";
			cin >> option;
			if (option == 1) {
				system("cls");
				staffsignup();
			}
			else if (option == 2) {
				system("cls");
			}
			else {
				cout << "Invalid option. Returning to login menu..." << endl;
				Sleep(2000);
				access();
			}
		}
		else if (exist == false) {
			cout << " Enter the OTP (Access otp.txt): ";
			while (otp_success == false) {
				srand(time(NULL));
				otp = rand() % (2000 - 1000 + 1) + 100;
				outFile2.open("otp.txt");
				outFile2 << otp;
				outFile2.close();
				cin >> otp_input;
				if (otp_input == otp) {
					otp_success = true;
					display_straight_lines();
					cout << "\tRegistration Completed! Logging in...\n";
					display_straight_lines();
					staffID = newstaffID;
					staff_username = staff_username_input;
					Sleep(2000);
				}
				else if (otp_input != otp) {
					otp_success = false;
					display_straight_lines();
					cout << " Invalid OTP. Returning to login menu..." << endl;
					display_straight_lines();
					Sleep(2000);
					break;
				}
			}
			if (otp_success = true) {
				outFile << "\n" << staffID << "\t" << staff_username_input << "\t" << staff_password_input; // appends newly registered staff account into textfile
			}
		}
	}
	inFile.close();
	outFile.close();
	outFile2.close();
	if (otp_success == true) {
		system("cls");
		staffmainmenu();
	}
}

// function to allow exisiting staff members to sign up (UMAR)
void stafflogin() {
	header();
	ifstream inFile;
	string staff_username_input, staff_password_input, staffusername_database, staffpassword_database;
	int staffid_database;
	bool available, retry;
	int option;
	available = false;
	retry = false;
	if (!inFile) {
		cout << "Please check the system for existing login textfile" << endl;
	}
	else {
		do {
			inFile.open("stafflogin.txt");
			display_straight_lines();
			cout << "\t\t\tStaff Login" << endl;
			display_straight_lines();
			cout << " Enter Staff Username: ";
			cin >> staff_username_input;
			cout << " Enter Password: ";
			cin >> staff_password_input;

			while (!inFile.eof() && !available)
			{
				inFile >> staffid_database >> staffusername_database >> staffpassword_database;
				if (staff_username_input == staffusername_database && staff_password_input == staffpassword_database) // if username and password matches with the account username and password in textfiles
				{
					staffID = staffid_database; // sets staffID value in global variable
					staff_username = staffusername_database; // sets staff_username in global variable
					available = true;
					retry = false;
					break;
				}
			}
			inFile.close();
			if (!available) {
				do {
					display_straight_lines();
					cout << "\tYou do not have an existing staff account." << endl;
					display_straight_lines();
					cout << " 1) Sign up for new staff account" << endl;
					cout << " 2) Retry log in" << endl;
					cout << " \n Option: ";
					cin >> option;
					if (option == 1) {
						system("cls");
						staffsignup();
						break;
					}
					else if (option == 2) {
						system("cls");
						retry = true;
						break;
					}
					else {
						cout << "Invalid Option. Please try again." << endl;
						system("cls");
					}
				} while (!(option == 1 || option == 2));
			}
		} while (retry == true);
	}
}

// function to allow existing users to login (UMAR)
void login()
{
	ifstream inFile;
	ifstream ProfileWCredits;
	ifstream OutstandingPayments;
	string password, username_database, password_database;
	int customerID2, option, credits_database;
	double menucost_database, bookingcost_database, totalcost_database;
	bool available;
	available = false;
	ProfileWCredits.open("profiles.txt");
	OutstandingPayments.open("outstandingpayment.txt");
	inFile.open("login.txt");
	if (!inFile) cout << "Error encountered.  Exit program. \n";
	else
	{
		header();
		cout << "\t\t\tLogin Page" << endl;
		display_straight_lines();
		cout << " Enter Username: ";
		cin >> username;
		cout << " Enter Password: ";
		cin >> password;

		while (!inFile.eof() && !available)
		{
			inFile >> customerID2 >> username_database >> password_database;
			if (username == username_database && password == password_database) // if username and password matches with the account username and password in textfiles
			{
				while (!ProfileWCredits.eof()) { // if username is found in textfile, next while loop will be run to find how much credits does the account have
					ProfileWCredits >> customerID2 >> username_database >> credits_database;
					if (username == username_database) {
						credits = credits_database; // credits (global variable) is set to the amount the account have
						break;
					}
				}
				while (!OutstandingPayments.eof()) {
					OutstandingPayments >> customerID2 >> username_database >> menucost_database >> bookingcost_database >> totalcost_database;
					if (username == username_database) {
						menu_cost = menucost_database; // sets menu cost (global variable) according to how much the account owe
						booking_cost = bookingcost_database; // sets booking cost (global variable) according to how much the account owe
						total_cost = totalcost_database; // sets total cost (global variable) according to how much the account owe
						break;
					}
				}
				customerID = customerID2; // sets customerID value in global variable
				available = true; break; // breaks if statement and while loop
			}
		}
		OutstandingPayments.close();
		ProfileWCredits.close();
		inFile.close();
		if (!available) {
			display_straight_lines();
			cout << right << setw(45) << "Sorry this account does not exist!\n";
			display_straight_lines();
			cout << " 1) Sign up for new account." << endl;
			cout << " 2) Retry log in." << endl;
			cout << " \nOption: ";
			cin >> option;
			switch (option) {
			case 1:
				system("cls");
				signUp();
				break; // breaks the switch statement only, finishes the if statement and proceeds to do while loop in main() 
			case 2:
				system("cls");
				login();  // login recursion
				break;
			}
		}
	}
}

// computes and returns the booking reservation cost (cost depends on no. of adults and children dining) (UMAR)
double book_reservation_cost(int adults, int children) {
	double cost;
	cout << fixed << setprecision(2);
	cost = (adults * 29.95) + (children * 12.95);
	return cost;
}

// function to decide whether the date of reservation is valid (eg: inputting 31 Feb 2022 returns false) (UMAR)
bool checkdate(int m, int d, int y) {
	if (!(2022 <= y))
		return false;
	if (!(1 <= m && m <= 12))
		return false;
	if (!(1 <= d && d <= 31))
		return false;
	if ((d == 31) && (m == 2 || m == 4 || m == 6 || m == 9 || m == 11))
		return false;
	if ((d == 30) && (m == 2))
		return false;
	if ((m == 2) && (d == 29) && (y % 4 != 0))
		return false;
	if ((m == 2) && (d == 29) && (y % 400 == 0))
		return true;
	if ((m == 2) && (d == 29) && (y % 100 == 0))
		return false;
	if ((m == 2) && (d == 29) && (y % 4 == 0))
		return true;

	return true;
}

// function to allow users to book for reservation (UMAR)
void book_reservation() {
	string password, username_input, password_input, reservation_date, reservation_meal, retained_username;
	bool found, datevalidation, returnmain;
	double reservation_cost;
	int option, bookingID, used_customer_id, adults, children, day, month, year, retained_userID;
	int customerID_database;
	string username_database;
	double menucost_database, bookingcost_database, totalcost_database;
	ifstream inFile;
	fstream file;
	ifstream inFile3;
	ifstream payfile;
	fstream tempPayFile;
	ofstream outFile3;
	found = false;
	returnmain = false;

	do {
		header();
		display_straight_lines();
		cout << "\t\t    Diners to Reserve" << endl;
		display_straight_lines();
		cout << " Number of Adults: ";
		cin >> adults;
		while (adults < 0) {
			cout << " Please enter a valid number!" << endl;
			Sleep(3000);
			system("cls");
			cout << "\t\t    Diners to Reserve" << endl;
			display_straight_lines();
			cout << " Number of Adults: ";
			cin >> adults;
		}
		cout << " Number of Children: ";
		cin >> children;
		while (children < 0) {
			cout << "Please enter a valid number!" << endl;
			Sleep(3000);
			system("cls");
			header();
			cout << " Number of Adults: " << adults << endl;
			cout << " Number of Children: ";
			cin >> children;
		}
		cout << endl;
		reservation_cost = book_reservation_cost(adults, children); // calculate reservation cost
		display_straight_lines();
		cout << "\t\t   Date of Reservation" << endl;
		display_straight_lines();
		cout << " Day of Reservation (DD): ";
		cin >> day;
		cout << " Month of Reservation (MM): ";
		cin >> month;
		cout << " Year of Reservation (YYYY): ";
		cin >> year;
		datevalidation = checkdate(month, day, year);
		while (datevalidation == false) {
			display_straight_lines();
			cout << "\t Invalid Reservation Date. Please try again!" << endl;
			display_straight_lines();
			Sleep(3000);
			system("cls");
			header();
			display_straight_lines();
			cout << "\t\t    Diners to Reserve" << endl;
			display_straight_lines();
			cout << " Number of Adults: " << adults << endl;
			cout << " Number of Children: " << children << endl << endl;
			display_straight_lines();
			cout << "\t\t   Date of Reservation" << endl;
			display_straight_lines();
			cout << " Day of Reservation (DD): ";
			cin >> day;
			cout << " Month of Reservation (MM): ";
			cin >> month;
			cout << " Year of Reservation (YYYY): ";
			cin >> year;
			datevalidation = checkdate(month, day, year);
		}

		outFile3.open("tempDateFile.txt");
		outFile3 << day << "/" << month << "/" << year;
		outFile3.close();

		system("cls");
		header();
		display_straight_lines();
		cout << "\t\t    Diners to Reserve" << endl;
		display_straight_lines();
		cout << " Number of Adults: " << adults << endl;
		cout << " Number of Children: " << children << endl;
		cout << endl;

		display_straight_lines();
		cout << "\t\t   Date of Reservation" << endl;
		display_straight_lines();
		cout << " Your reservation date: " << day << "/" << month << "/" << year << endl << endl;

		display_straight_lines();
		cout << "\t\t       Dining Time" << endl;
		display_straight_lines();

		cout << " 1) Lunch  | 12:00 - 16:30" << endl;
		cout << " 2) Dinner | 18:30 - 22:30" << endl;
		cout << "Option: ";
		cin >> option;
		if (option == 1) {
			system("cls");
			header();
			display_straight_lines();
			cout << "\t\t    Diners to Reserve" << endl;
			display_straight_lines();
			cout << " Number of Adults: " << adults << endl;
			cout << " Number of Children: " << children << endl << endl;

			display_straight_lines();
			cout << "\t\t   Date of Reservation" << endl;
			display_straight_lines();
			cout << " Your reservation date: " << day << "/" << month << "/" << year << endl << endl;

			display_straight_lines();
			cout << "\t\t       Dining Time" << endl;
			display_straight_lines();
			cout << " Lunch | 12:00 - 16:30" << endl << endl;
			reservation_meal = "Lunch|12:00-16:30";
			display_straight_lines();
		}
		else if (option == 2) {
			system("cls");
			header();
			display_straight_lines();
			cout << "\t\t    Diners to Reserve" << endl;
			display_straight_lines();
			cout << " Number of Adults: " << adults << endl;
			cout << " Number of Children: " << children << endl << endl;

			display_straight_lines();
			cout << "\t\t   Date of Reservation" << endl;
			display_straight_lines();
			cout << " Your reservation date: " << day << "/" << month << "/" << year << endl << endl;

			display_straight_lines();
			cout << "\t\t       Dining Time" << endl;
			display_straight_lines();
			cout << " Dinner | 18:30 - 22:30" << endl << endl;
			reservation_meal = "Dinner|18:30-22:30";
			display_straight_lines();
		}
		else {
			while (!(option == 1 || option == 2)) {
				cout << "Invalid option. Please try again!" << endl;
				Sleep(3000);
				system("cls");
				header();
				display_straight_lines();
				cout << "\t\t    Diners to Reserve" << endl;
				display_straight_lines();
				cout << " Number of Adults: " << adults << endl;
				cout << " Number of Children: " << children << endl;
				cout << endl;

				display_straight_lines();
				cout << "\t\t   Date of Reservation" << endl;
				display_straight_lines();
				cout << " Your reservation date: " << day << "/" << month << "/" << year << endl << endl;

				display_straight_lines();
				cout << "\t\t       Dining Time" << endl;
				display_straight_lines();
				cout << "1) Lunch | 12:00 - 16:30" << endl;
				cout << "2) Dinner | 18:30 - 22:30" << endl;
				cout << " Option: ";
				cin >> option;
				if (option == 1) {
					system("cls");
					header();
					display_straight_lines();
					cout << "\t\t    Diners to Reserve" << endl;
					display_straight_lines();
					cout << " Number of Adults: " << adults << endl;
					cout << " Number of Children: " << children << endl << endl;

					display_straight_lines();
					cout << "\t\t   Date of Reservation" << endl;
					display_straight_lines();
					cout << " Your reservation date: " << day << "/" << month << "/" << year << endl << endl;

					display_straight_lines();
					cout << "\t\t       Dining Time" << endl;
					display_straight_lines();
					cout << " Lunch | 12:00 - 16:30" << endl << endl;
					reservation_meal = "Lunch|12:00-16:30";
					display_straight_lines();
					reservation_meal = "Lunch|12:00-16:30";
					display_straight_lines();
				}
				else if (option == 2) {
					system("cls");
					header();
					display_straight_lines();
					cout << "\t\t    Diners to Reserve" << endl;
					display_straight_lines();
					cout << " Number of Adults: " << adults << endl;
					cout << " Number of Children: " << children << endl << endl;

					display_straight_lines();
					cout << "\t\t   Date of Reservation" << endl;
					display_straight_lines();
					cout << " Your reservation date: " << day << "/" << month << "/" << year << endl << endl;

					display_straight_lines();
					cout << "\t\t       Dining Time" << endl;
					display_straight_lines();
					cout << " Lunch | 12:00 - 16:30" << endl << endl;
					reservation_meal = "Dinner|18:30-22:30";
					display_straight_lines();
				}
			}
		}
		retained_username = username; // variable to keep the same username in main menu so to prevent it from changing when user enters wrong username or password
		retained_userID = customerID; // variable to keep the same user ID in main menu so to prevent it from changing when user enters wrong username or password
		cout << "\n Confirm booking?" << endl;
		cout << " 1) Yes" << endl;
		cout << " 2) No" << endl;
		cout << " Option: ";
		cin >> option;
		if (option != 1) {
			returnmain = true;
			break;
		}
		switch (option) {
		case 1:
			inFile.open("login.txt");
			if (!inFile)
				cout << "Sorry, our software is currently undergoing maintenance. Please try again later." << endl;
			else {
				system("cls");
				header();
				display_straight_lines();
				cout << "\t\tIdentity Verification" << endl;
				display_straight_lines();
				cout << " To verify your identity, please enter your Password" << endl; // Verify identity before booking
				cout << " Password: ";
				cin >> password_input;
				while (!inFile.eof() && !found) {
					inFile >> used_customer_id >> username_database >> password;
					if (username == username_database && password == password_input)
					{
						found = true; break;
					}
				}
				inFile.close();
				if (!found) {
					username = retained_username;
					customerID = retained_userID;
					system("cls");
					header();
					display_straight_lines();
					cout << "\t\tInvalid username or password." << endl;
					display_straight_lines();
					cout << " 1) Retry" << endl;
					cout << " 2) Return to Main Menus" << endl;
					cout << " \n Option: ";
					cin >> option;
					switch (option) {
					case 1:
						system("cls");
						break; // break the switch statement
					case 2:
						returnmain = true;
						system("cls");
						break; // break the switch statement
					default:
						display_straight_lines();
						cout << "\t  Invalid Option! Returning to main menu..." << endl;
						display_straight_lines();
						Sleep(3000);
						system("cls");
						returnmain = true;
					}
				}
				else {
					file.open("reservationlist.txt", fstream::app); // file to store all reservation made by customers
					payfile.open("outstandingpayment.txt"); // original file to store outstanding payment fees for check out payment purposes
					tempPayFile.open("temp.txt", fstream::app); // new textfile to store updated outstanding payment fees for check out payment purposes
					inFile3.open("tempDateFile.txt");
					while (!inFile3.eof()) {
						inFile3 >> reservation_date;
					}
					inFile3.close();
					if (!file) cout << "Due to a technical error, your booking has not been saved." << endl;
					else {
						system("cls");
						header();
						srand(time(NULL));
						bookingID = rand() % (2000 - 1000 + 1) + 1000;
						file << "\n" << customerID << "\t" << username << "\t" << password << "\t" << day << "/" << month << "/" << year << "\t" << reservation_meal << "\t" << adults << "\t" << children << "\t" << reservation_cost << "\t" << bookingID;
						while (!payfile.eof()) { // ALTERING outstandingpayment.txt data
							payfile >> customerID_database >> username_database >> menucost_database >> bookingcost_database >> totalcost_database;
							if (!(customerID == customerID_database)) {
								tempPayFile << "\n" << customerID_database << "\t" << username_database << "\t" << menucost_database << "\t" << bookingcost_database << "\t" << totalcost_database;
							}
							else if (customerID == customerID_database) {
								booking_cost = reservation_cost;
								total_cost += booking_cost; // add value to the global variable, total_cost. total_cost is used to calculate the total amount of payment
								tempPayFile << "\n" << customerID << "\t" << username << "\t" << menu_cost << "\t" << booking_cost << "\t" << total_cost;
							}
						}
						display_straight_lines();
						cout << "   Booking confirmed. See you at Pantaleone's Pizza!" << endl;
						display_straight_lines();
						booking_header(username, bookingID, reservation_date, reservation_meal, adults, children, reservation_cost);
						payfile.close();
						tempPayFile.close();
						remove("outstandingpayment.txt");
						rename("temp.txt", "outstandingpayment.txt");
						file.close();
						Sleep(5000);
						returnmain = true;
					}
				}
				break;
			}
		case 2:
			returnmain = true;
		default:
			returnmain = true;
		}
	} while (returnmain != true);
	system("cls");
}

// function to allow users to check for reservation (UMAR)
void check_reservation() {
	string username_database, password, reservation_date, meal;
	int option, adults, children, bookingID_input, bookingID, customerID2;
	double reservation_cost;
	bool found, return_menu = false;
	found = false;
	fstream inFile;
	header();
	inFile.open("reservationlist.txt");
	display_straight_lines();
	cout << "\t\t Reservation Check" << endl;
	display_straight_lines();
	do {
		if (!inFile) {
			cout << "Due to a technical error, your booking could not be found. Please try again later." << endl;
		}
		else {
			while (!inFile.eof() && !found) {
				inFile >> customerID2 >> username_database >> password >> reservation_date >> meal >> adults >> children >> reservation_cost >> bookingID;
				if (customerID == customerID2) {
					found = true;
					break;
				}
			}
			inFile.close();
			if (!found) {
				display_straight_lines();
				cout << "   Sorry, it seems that we can't find your booking!" << endl;
				display_straight_lines();
				cout << " 1) Return to main menu" << endl;
				cout << " 2) Retry" << endl;
				cout << " \nOption: ";
				cin >> option;
				switch (option) {
				case 1:
					mainmenu();
					break;
				case 2:
					check_reservation();
					break;
				default:
					while (!(option == 1 || option == 2))
					{
						display_straight_lines();
						cout << " Invalid option. Please try again!" << endl;
						display_straight_lines();
						cout << " 1) Return to main menu" << endl;
						cout << " 2) Retry" << endl;
						cout << " Option: ";
						cin >> option;
						switch (option) {
						case 1:
							mainmenu();
							break;
						case 2:
							check_reservation();
							break;
						}
					}
				}
			}
			else {
				booking_header(username, bookingID, reservation_date, meal, adults, children, reservation_cost);
				cout << "\n 1) Return Menu" << endl;
				cout << " Option: ";
				cin >> option;
				if (option == 1) {
					system("cls");
					return_menu = true;
				}
				else {
					while (option != 1) {
						system("cls");
						header();
						display_straight_lines();
						cout << "\t\t Reservation Check" << endl;
						display_straight_lines();
						booking_header(username, bookingID, reservation_date, meal, adults, children, reservation_cost);
						display_straight_lines();
						cout << "\t Invalid option. Please try again!" << endl;
						display_straight_lines();
						cout << "1) Return Menu" << endl;
						cout << "Option: ";
						cin >> option;
						if (option == 1) {
							system("cls");
							return_menu = true;
						}
					}
				}
			}
		}
	} while (return_menu != true);
}

// function to allow users to order their desired course (UMAR)
void order_menu() {
	int option, customerID_database;
	double order_cost, menucost_database, bookingcost_database, totalcost_database;
	string order, username_database;
	ifstream inFile2;
	fstream outFile;
	fstream outFile2;
	inFile2.open("outstandingpayment.txt"); // ORIGINAL OUTSTANDINGPAYMENT TEXT FILE
	outFile.open("order.txt", ofstream::app); // ORDER TEXT FILE
	outFile2.open("temp.txt", ofstream::app); // TEMPORARY TEXT FILE FOR OUTSTANDINGPAYMENT
	do {
		header();
		display_straight_lines();
		cout << "\t\t       Course Menu" << endl;
		display_straight_lines();
		order_header();
		display_straight_lines();
		cout << "\t Which course would you like to order?" << endl;
		display_straight_lines();
		cout << " 1) 3 Course Meal" << endl;
		cout << " 2) 4 Course Meal" << endl;
		cout << " \n Option: ";
		cin >> option;
		if (option == 1) {
			order_cost = 69;
			menu_cost = 69;
			order = "3CourseMeal";
			while (!inFile2.eof()) {
				inFile2 >> customerID_database >> username_database >> menucost_database >> bookingcost_database >> totalcost_database;
				if (!(customerID == customerID_database)) {
					outFile2 << "\n" << customerID_database << "\t" << username_database << "\t" << menucost_database << "\t" << bookingcost_database << "\t" << totalcost_database; // adds other account incurred cost into the temporary textfile
				}
				else if (customerID == customerID_database) { // checks for account's existing incurred cost in the textfile. if found, add the ordered food cost to the total cost.
					total_cost += order_cost; // adds the cost of the order to the total cost (global variable)
					outFile2 << "\n" << customerID_database << "\t" << username_database << "\t" << order_cost << "\t" << bookingcost_database << "\t" << total_cost; // changes the existing cost to the new cost incurred in the temporary textfile
				}
			}
		}
		else if (option == 2) {
			order_cost = 99;
			menu_cost = 99;
			order = "4CourseMeal";
			while (!inFile2.eof()) {
				inFile2 >> customerID_database >> username_database >> menucost_database >> bookingcost_database >> totalcost_database;
				if (!(customerID == customerID_database)) {
					outFile2 << "\n" << customerID_database << "\t" << username_database << "\t" << menucost_database << "\t" << bookingcost_database << "\t" << totalcost_database; // adds other account incurred cost into the temporary textfile
				}
				else if (customerID == customerID_database) { // checks for account's existing incurred cost in the textfile. if found, add the ordered food cost to the total cost.
					total_cost += order_cost; // adds the cost of the order to the total cost (global variable)
					outFile2 << "\n" << customerID_database << "\t" << username_database << "\t" << order_cost << "\t" << bookingcost_database << "\t" << total_cost; // changes the existing cost to the new cost incurred in the temporary textfile
				}
			}
		}
		else if (!(option == 1 || option == 2))
		{
			display_straight_lines();
			cout << "\t Invalid option. Please try again!" << endl;
			display_straight_lines();
			Sleep(2000);
			system("cls");
		}
	} while (!(option == 1 || option == 2));

	inFile2.close();
	outFile2.close();
	remove("outstandingpayment.txt");
	rename("temp.txt", "outstandingpayment.txt");
	display_straight_lines();
	cout << "\t\tSending your order..." << endl;
	if (!outFile) {
		cout << "Fail to send your order. Please contact our staffs.";
	}
	else {
		outFile << "\n" << customerID << "\t" << username << "\t" << order << "\t" << order_cost; // appends customer's order to order.txt
		outFile.close();
		Sleep(1000);
		display_straight_lines();
		cout << "\t\t Order Submitted!" << endl;
		display_straight_lines();
		do {
			cout << "\n Would you like to make payment now?" << endl;
			cout << " 1) Yes" << endl;
			cout << " 2) No" << endl;
			cout << " \nOption: ";
			cin >> option;
			if (option == 1) {
				display_straight_lines();
				cout << " \tTransferring to payment section..." << endl;
				display_straight_lines();
				Sleep(2000);
				system("cls");
				payment();
				break;
			}
			else if (option == 2) {
				cout << " Returning to main menu..." << endl;
				Sleep(2000);
				system("cls");
				mainmenu();
				break;
			}
			else if (!(option == 1 || option == 2)) {
				display_straight_lines();
				cout << " Invalid option. Please try again!" << endl;
				display_straight_lines();
				Sleep(2000);
				system("cls");
				header();
				order_header();
			}
		} while (!(option == 1 || option == 2));
	}
}

// computes gst for payment() (UMAR)
double calculate_gst(double subtotal) {
	double gst_price = 0.07 * subtotal;
	return gst_price;
}

// computes grand total owed by customers for payment() (UMAR)
double calculate_grandtotal(double course_price, double reservationcost, double gst, double discount = 0) {
	double grand_total = (course_price + reservationcost + gst) - discount;
	return grand_total;
}

// function to allow customers to pay (could have decomposed into different functions but was lacking of time) (UMAR)
void payment() {
	string username_database, reservationdate_database, meal_database, adultsreservation_database, childrenreservation_database, courseordered_database, password_database, debitcreditnumber_database, debitcreditnumber, debitcreditnumber_input, code;
	int customerID_database, bookingID_database;
	int option;
	string status, dateofreservation, course_ordered, payment_code;
	double reservation_cost, course_price, subtotal, discount_cost = 0, gst, grandtotal, menucost_orderdatabase, credits_database, credits_input, discount = 0;
	double menucost_database, reservationcost_database, reservationcost_reservationdatabase, totalcost_database;
	bool exit_payment_summary = false;
	bool successful_payment = false;

	ifstream inFile; // input file stream for outstandingpayment.txt
	ifstream inFile2; // input file stream for profile.txt
	ifstream inFile3; // input file stream for debitcreditcc.txt
	ifstream inFile4; // input file stream for order.txt
	ifstream inFile5; // input file stream for reservationlist.txt
	ofstream outFile; // output file stream for outstandingpayment.txt
	ofstream outFile2; // output file stream for profile.txt
	ofstream outFile3; // output file stream for debitcreditcc.txt
	ofstream outFile4; // output file stream for order.txt
	ofstream outFile5; // output file stream for reservationlist.txt
	ofstream outFile6; // output file stream for paidpayments.txt

	if (booking_cost != 0 && menu_cost != 0) {
		inFile.open("outstandingpayment.txt");
		while (!inFile.eof()) {
			inFile >> customerID_database >> username_database >> menucost_database >> reservationcost_database >> totalcost_database;
			if (customerID == customerID_database) {
				course_price = menucost_database;
				reservation_cost = reservationcost_database;
				subtotal = totalcost_database;
				break;
			}
		}
		inFile.close();
		inFile5.open("reservationlist.txt");
		while (!inFile5.eof()) {
			inFile5 >> customerID_database >> username_database >> password_database >> reservationdate_database >> meal_database >> adultsreservation_database >> childrenreservation_database >> reservationcost_reservationdatabase >> bookingID_database;
			if (customerID == customerID_database) {
				dateofreservation = reservationdate_database;
				break;
			}
		}
		inFile5.close();
		inFile4.open("order.txt");
		while (!inFile4.eof()) {
			inFile4 >> customerID_database >> username_database >> courseordered_database >> menucost_orderdatabase;
			if (customerID == customerID_database) {
				if (courseordered_database == "3CourseMeal") {
					course_ordered = "3 Course Meal";
				}
				else if (courseordered_database == "4CourseMeal") {
					course_ordered = "4 Course Meal";
				}
				break;
			}
		}
		inFile4.close();
		inFile2.open("profiles.txt");
		while (!inFile2.eof()) {
			inFile2 >> customerID_database >> username_database >> credits_database;
			if (customerID == customerID_database) {
				credits = credits_database;
				break;
			}
		}
		inFile2.close();
		do {
			header();
			display_straight_lines();
			cout << "\t\t   Payment Section" << endl;
			display_straight_lines();
			discount_cost = discount * subtotal;
			gst = calculate_gst((subtotal * ((100 - discount) / 100)) - discount_cost);
			grandtotal = calculate_grandtotal(course_price, reservation_cost, gst, discount_cost);
			cout << "\n Your Current Accumulated Credits: " << credits << endl << endl;
			payment_summary_header(username, customerID, "UNPAID", dateofreservation, course_ordered, reservation_cost, course_price, subtotal, discount_cost, gst, grandtotal);
			cout << " 1) Check account credits and discount table" << endl;
			cout << " 2) Apply discount with credits" << endl;
			cout << " 3) Proceed to payment" << endl;
			cout << " 4) Return to main menu" << endl;
			cout << " Option: ";
			cin >> option;
			if (option == 1) {
				do {
					system("cls");
					header();
					credit_discount_table();
					cout << "\nYour Current Accumulated Credits: " << credits << endl << endl;
					cout << "1) Return to Payment Summary" << endl;
					cout << "Option: ";
					cin >> option;
					if (option == 1) {
						system("cls");
						break;
					}
					else {
						cout << "Invalid option. Please try again.";
						Sleep(3000);
					}
				} while (option != 1);
			}
			else if (option == 2) {
				do {
					system("cls");
					header();
					payment_summary_header(username, customerID, "UNPAID", dateofreservation, course_ordered, reservation_cost, course_price, subtotal, 0, gst, grandtotal);
					display_straight_lines();
					cout << "\t   Apply Discount With Your Credits" << endl;
					display_straight_lines();
					cout << "\n Your Current Accumulated Credits: " << credits << endl << endl;
					cout << " Enter Amount of Credits for Discount: ";
					cin >> credits_input;
					cout << "\n 1) Confirm" << endl;
					cout << " 2) Don't Confirm" << endl;
					cout << " Option: ";
					cin >> option;
					system("cls");
					header();
					payment_summary_header(username, customerID, "UNPAID", dateofreservation, course_ordered, reservation_cost, course_price, subtotal, 0, gst, grandtotal);
					cout << "\n Your Current Accumulated Credits: " << credits << endl << endl;
					cout << "Enter Amount of Credits for Discount: " << credits_input << endl;;
					if (option == 1) {
						if (credits_input > credits) { // compares the amount of credits with the global variable credit
							cout << "\n Sorry, you have " << fixed << setprecision(0) << credits_input - credits << " lesser credits than what you entered. Please try again" << endl;
							Sleep(3000);
							system("cls");
						}
						else {
							if (credits_input <= 50)
								discount = 0.02;
							else if (credits_input <= 100)
								discount = 0.04;
							else if (credits_input <= 150)
								discount = 0.06;
							else if (credits_input <= 200)
								discount = 0.08;
							else if (credits_input > 200)
								discount = 0.10;
							credits = credits - credits_input;
							cout << "\n Your discount of " << discount * 100 << "% has been applied." << endl;
							cout << " You have a balance of " << credits << " in your account." << endl;
							cout << "\n Updating your payment summary..." << endl;
							// edit profiles.txt here
							Sleep(3000);
							system("cls");
							break;
						}
					}
					else if (option == 2) {
					}
					else {
						cout << "Invalid option. Please try again!" << endl;
						Sleep(3000);
					}
				} while (!(discount > 0));
			}
			else if (option == 3) {
				do {
					display_straight_lines();
					cout << "\t\t Select Payment Method" << endl;
					display_straight_lines();
					cout << " 1) Debit/Credit Card" << endl;
					cout << " 2) Cash Payment" << endl;
					cout << " Option: ";
					cin >> option;
				} while (!(option == 1 || option == 2));
				if (option == 1) {
					inFile3.open("debitcreditcc.txt");
					display_straight_lines();
					cout << "\tRetrieving your debit / credit card number..." << endl;
					display_straight_lines();
					Sleep(3000);
					while (!inFile3.eof()) {
						inFile3 >> customerID_database >> username_database >> debitcreditnumber_database;
						if (customerID == customerID_database) {
							debitcreditnumber = debitcreditnumber_database;
						}
					}
					inFile3.close();
					cout << " Your Credit/Debit Card No.: " << debitcreditnumber << endl;
					if (debitcreditnumber[0] == '4') {
						cout << " Credit / Debit Card Type: Visa" << endl;
						successful_payment = true;
					}
					else if (debitcreditnumber[0] == '5') {
						cout << " Credit / Debit Card Type: Mastercard" << endl;
						successful_payment = true;
					}
					else if (debitcreditnumber[0] == '6') {
						cout << " Credit / Debit Card Type: Discover" << endl;
						successful_payment = true;
					}
					else if (debitcreditnumber[0] == '3') {
						cout << " Credit / Debit Card Type: American Express" << endl;
						successful_payment = true;
					}
					else if (debitcreditnumber[0] == '0') {
						cout << " You do not have any card saved to this account." << endl;
						cout << " Do you want to add your card?" << endl;
						cout << " 1) Yes" << endl;
						cout << " 2) No" << endl;
						cout << " Option: ";
						cin >> option;
						if (option == 1) {
							display_straight_lines();
							cout << "\t\t   Add Credit/Debit Card" << endl;
							display_straight_lines();
							cout << " Enter your 16 Digits Debit / Credit Card No.: ";
							cin >> debitcreditnumber_input;
							if (debitcreditnumber_input.length() < 16 || debitcreditnumber_input.length() > 16) { // if debit/credit no is not valid
								cout << "\n You have entered an invalid Credit / Debit Card Number." << endl;
								cout << " Returning to main menu..." << endl;
								Sleep(3000);
							}
							else { // if debit/credit no is valid
								inFile3.open("debitcreditcc.txt");
								outFile3.open("debitcreditcctemp.txt", ofstream::app); // adds customer's new debit/credit card no. to temp version of debitcreditcc.txt
								while (!inFile3.eof()) {
									inFile3 >> customerID_database >> username_database >> debitcreditnumber_database;
									if (!(customerID == customerID_database && username == username_database)) {
										outFile3 << "\n" << customerID_database << "\t" << username_database << "\t" << debitcreditnumber_database;
									}
									else if (customerID == customerID_database && username == username_database) {
										outFile3 << "\n" << customerID << "\t" << username << "\t" << debitcreditnumber_input; // appends customer's new debit/credit card no. to temp version of debitcreditcc.txt
									}
								}
								inFile3.close();
								outFile3.close();
								remove("debitcreditcc.txt");
								rename("debitcreditcctemp.txt", "debitcreditcc.txt");
								cout << " Processing your payment..." << endl;
								successful_payment = true;
								exit_payment_summary = true; // breaks out of the do while loop after adding new payment method
							}
						}
						else { // returns user to main menu
							exit_payment_summary = true; // by default, user will be using cash to pay for the items
						}
					}
					exit_payment_summary = true; // breaks out of the do while loop if user has a payment method initially
				}
				else if (option == 2) {
					display_straight_lines();
					cout << "\t\t  Cash Payment" << endl;
					display_straight_lines();
					cout << " Please make your payment at the counter after dining in." << endl;
					cout << " Once payment has been done, our staff will pass a code to \n enter a code once the transaction is successful." << endl << endl;
					cout << " 1) Enter code" << endl;
					cout << " 2) Return to main menu" << endl;
					cout << " Option: ";
					cin >> option;
					if (option == 1) {
						do {
							cout << " Code: ";
							cin >> payment_code;
							if (payment_code == "P4NT4L3ON3") {
								successful_payment = true;
								exit_payment_summary = true;
							}
							else {
								do {
									cout << " Invalid Code!" << endl;
									cout << " 1) Retry" << endl;
									cout << " 2) Return to main menu" << endl;
									cout << " Option: ";
									cin >> option;
									if (option == 1) {
										break;
									}
									else if (option == 2) {
										cout << " Returning to main menu..." << endl;
										exit_payment_summary = true;
										Sleep(2000);
										system("cls");
									}
									else {
										cout << " Invalid option. Please try again." << endl;
									}
								} while (!(successful_payment == true || option == 2));
							}
						} while (!(successful_payment == true || option == 2));
					}
					else {
						system("cls");
						exit_payment_summary = true;
					}
				}
			}
		} while (exit_payment_summary != true);

		if (successful_payment == true) {
			inFile.open("outstandingpayment.txt");
			outFile.open("tempoutstandingpayment.txt", ofstream::app);
			outFile6.open("paidpayments.txt", ofstream::app);
			if (!inFile) {
				cout << "Sorry, an error has occurred in the server. Please try again letter.";
			}
			else {
				while (!inFile.eof()) {
					inFile >> customerID_database >> username_database >> menucost_database >> reservationcost_database >> totalcost_database;
					if (!(customerID == customerID_database)) {
						outFile << "\n" << customerID_database << "\t" << username_database << "\t" << menucost_database << "\t" << reservationcost_database << "\t" << totalcost_database;
					}
					else if (customerID == customerID_database) {
						outFile6 << "\n" << customerID << "\t" << username << "\t" << menu_cost << "\t" << booking_cost << "\t" << total_cost; // sends data to paid payments
						menu_cost = 0; // sets global variable for food ordered to 0 after payment
						booking_cost = 0; // sets global variable for booking cost to 0 after payment
						total_cost = 0; // sets global variable for total cost to 0 after payment
						outFile << "\n" << customerID << "\t" << username << "\t" << menu_cost << "\t" << booking_cost << "\t" << total_cost;
					}
				}
				inFile.close();
				outFile.close();
				outFile6.close();
				remove("outstandingpayment.txt");
				rename("tempoutstandingpayment.txt", "outstandingpayment.txt"); // replace outstanding payment owed by customers to 0
			}
			inFile2.open("profiles.txt");
			outFile2.open("tempprofiles.txt");
			if (!inFile2) {
				cout << "Your points has not been awarded. Please contact our staff";
			}
			else {
				while (!inFile2.eof()) {
					inFile2 >> customerID_database >> username_database >> credits_database;
					if (!(customerID == customerID_database)) {
						outFile2 << "\n" << customerID_database << "\t" << username_database << "\t" << credits_database;
					}
					else if (customerID == customerID_database) {
						credits += 10;
						outFile2 << "\n" << customerID << "\t" << username << "\t" << credits;
					}
				}
				inFile2.close();
				outFile2.close();
				remove("profiles.txt");
				rename("tempprofiles.txt", "profiles.txt");
			}
			display_straight_lines();
			cout << "\t\tPayment Success" << endl;
			display_straight_lines();

			cout << " Payment has been made successfully. You have been \n credited 10 points." << endl;
			cout << " Proceeding to main menu..." << endl;
			Sleep(3000);
			system("cls");
		}
	}
	else {
		header();
		cout << "\n";
		display_straight_lines();
		cout << " Sorry, payments are available only after you make an order \n and reservation." << endl;
		cout << " Returning to main menu..." << endl;
		display_straight_lines();
		Sleep(3000);
		system("cls");
	}
	system("cls");
}

// function to allow customers to cancel their reservation and course ordered (UMAR)
void cancel_reservation() {
	ifstream inFile; // input file stream for reservationlist.txt
	ifstream inFile2; // input file stream for outstandingpayment.txt
	ifstream inFile3; // input file stream for order.txt
	ofstream outFile; // output file stream for reservationlist.txt
	ofstream outFile2; // output file stream for outstanding payment.txt
	ofstream outFile3; // output file stream for order.txt
	int option, customerID_database, bookingID_database, adults_booking, children_booking;
	string username_database, password_database, meal_database, reservationdate_database;
	double reservationcost_database, menucost_database, totalcost_database;
	bool change;
	change = false;
	do {
		header();
		display_straight_lines();
		cout << "\t\t Booking Cancellation" << endl;
		display_straight_lines();
		cout << " Are you sure you want to cancel your booking?" << endl;
		cout << " 1) Yes" << endl;
		cout << " 2) No" << endl;
		cout << " \n Option: ";
		cin >> option;
		if (option == 1) {
			total_cost = 0; // resets the total cost owed to 0
			menu_cost = 0; // resets the food ordered cost owed to 0
			booking_cost = 0; // resets the booking cost owed to 0
			inFile2.open("outstandingpayment.txt");
			outFile2.open("tempoutstandingpayment.text", ofstream::app);
			while (!inFile2.eof()) { // resets outstanding payment owed to 0
				inFile2 >> customerID_database >> username_database >> menucost_database >> reservationcost_database >> totalcost_database;
				if (!(customerID == customerID_database && username == username_database))
				{
					outFile2 << "\n" << customerID_database << "\t" << username_database << "\t" << menucost_database << "\t" << reservationcost_database << "\t" << totalcost_database;
				}
				else {
					outFile2 << "\n" << customerID << "\t" << username << "\t" << menu_cost << "\t" << booking_cost << "\t" << total_cost;
				}
			}
			inFile2.close();
			outFile2.close();

			inFile3.open("order.txt");
			outFile3.open("temporder.txt");
			while (!inFile3.eof()) { // removes order from order.txt
				inFile3 >> customerID_database >> username_database >> meal_database >> menucost_database;
				if (!(customerID == customerID_database && username == username_database)) {
					outFile3 << "\n" << customerID_database << "\t" << username_database << "\t" << meal_database << "\t" << menucost_database;
				}
				else {
					change = true;
				}
			}
			inFile3.close();
			outFile3.close();

			inFile.open("reservationlist.txt"); // opens original textfile
			outFile.open("temp.txt", ofstream::app); // opens temporary textfile to store new data
			while (!inFile.eof()) { // removes reservation from reservation.txt
				inFile >> customerID_database >> username_database >> password_database >> reservationdate_database >> meal_database >> adults_booking >> children_booking >> reservationcost_database >> bookingID_database;
				if (!(customerID == customerID_database && username == username_database)) {  // filtering datas from the data that needs to be removed
					outFile << "\n" << customerID_database << "\t" << username_database << "\t" << password_database
						<< "\t" << reservationdate_database << "\t" << meal_database << "\t" << adults_booking << "\t" << children_booking << "\t" << reservationcost_database << "\t" << bookingID_database;
				}
				else {
					change = true; // if username == username_database, then the data wont be added to new textfile. hence, true. else if there's no name exist, it will retain change = false
				}
			}
			inFile.close();
			outFile.close();
			if (!change) {
				display_straight_lines();
				cout << "Cancellation fail. You do not have a reservation currently." << endl;
				display_straight_lines();
				remove("temp.txt"); // removes temporary file with the same data as original
				remove("tempoutstandingpayment.text");
				remove("temporder.txt");
			}
			else {
				remove("order.txt");
				remove("reservationlist.txt"); // deletes original textfile
				remove("outstandingpayment.txt");

				rename("temporder.txt", "order.txt");
				rename("temp.txt", "reservationlist.txt"); // renames new textfile to original textfile name with new stored date
				rename("tempoutstandingpayment.text", "outstandingpayment.txt");
				display_straight_lines();
				cout << "   Your booking has successfully been cancelled." << endl;
				display_straight_lines();
			}
			Sleep(5000);
			system("cls");
			break;
		}
		else if (option == 2) {
			system("cls");
			break;
		}
		else {
			cout << "Invalid option! Please try again." << endl;
			Sleep(3000);
			system("cls");
		}
	} while (!(option == 1 || option == 2));
}

// header to display orders placed by customers (UMAR)
void display_staff_order_header() {
	char horizontal_lines = 196, vertical_lines = 179;
	int breadth = 0;
	cout << left << setw(34) << "\t\t\tOrder List" << endl;
	while (breadth < 58) {
		cout << horizontal_lines;
		breadth++;
	}
	breadth = 0;
	cout << endl;
	cout << left << setw(10) << "  User ID" << setw(2) << vertical_lines << setw(15) << "Username"
		<< setw(2) << vertical_lines << setw(18) << "Course Ordered" << setw(2) << vertical_lines << "Cost ($)" << endl;
	while (breadth < 58) {
		cout << horizontal_lines;
		breadth++;
	}
	cout << endl;
	breadth = 0;
}

// staff menu relating to orders (UMAR)
void staff_check_order() {
	int option;
	header();
	display_straight_lines();
	cout << "\t\t    Admin Order Menu" << endl;
	display_straight_lines();
	cout << " 1) Check All Orders" << endl;
	cout << " 2) Remove Orders" << endl;
	cout << " 3) Update Existing Orders" << endl;
	cout << " 4) Return to Main Menu" << endl;
	cout << " Option: ";
	cin >> option;
	system("cls");

	if (option == 1) {
		staff_display_orders();
	}
	else if (option == 2) {
		header();
		display_straight_lines();
		cout << "\t\t Customer's Order Removal" << endl;
		display_straight_lines();
		cout << " 1) Remove Order Using Customer's ID" << endl;
		cout << " 2) Remove Order Using Username" << endl;
		cout << " 3) Return to Main Menu" << endl;
		cout << " Option: ";
		cin >> option;
		if (option == 1) {
			system("cls");
			remove_order_customer_id_order_txt(); // DONE
		}
		else if (option == 2) {
			system("cls");
			remove_order_username_order_txt(); // DONE
		}
		else if (option == 3) {
			system("cls");
		}
	}
	else if (option == 3) {
		header();
		display_straight_lines();
		cout << "\t\t Update Customer's Order" << endl;
		display_straight_lines();
		cout << " 1) Update Order Using Customer's ID" << endl;
		cout << " 2) Update Order Using Username" << endl;
		cout << " 3) Return to Main Menu" << endl;
		cout << " Option: ";
		cin >> option;
		if (option == 1) {
			system("cls");
			update_order_customer_id_order_txt(); // DONE
		}
		else if (option == 2) {
			system("cls");
			update_order_username_order_txt(); // DONE
		}
		else if (option == 3) {
			system("cls");
		}
	}
	else if (option == 4) {
	}
}

// function to display all customer orders (UMAR)
void staff_display_orders() {
	int option, userID_database, reservationID, reservationID_database, reservationID_input, adults, children;
	string username_database, meal_database, username_input;
	char vertical_lines = 179;
	double mealcost_database;
	ifstream inFile;

	do {
		header();
		inFile.open("order.txt");
		if (!inFile) {
			cout << "An error has occurred. Please try again." << endl;
		}
		else {
			display_staff_order_header();
			while (!inFile.eof()) {
				inFile >> userID_database >> username_database >> meal_database >> mealcost_database;
				if (meal_database == "4CourseMeal") {
					meal_database = "4 Course Meal";
				}
				else if (meal_database == "3CourseMeal") {
					meal_database = "3 Course Meal";
				}
				cout << "  " << left << setw(8) << userID_database << setw(2) << vertical_lines << setw(15) << username_database << setw(2) << vertical_lines << setw(18) << meal_database << setw(2) << vertical_lines << fixed << setprecision(2) << mealcost_database << endl;
			}
			display_straight_lines();
		}
		inFile.close();
		cout << "\n 1) Return to Main Menu" << endl;
		cout << " Option: ";
		cin >> option;
		if (option != 1) {
			cout << "Invalid Option. Please try again." << endl;
			Sleep(2000);
			system("cls");
		}
		else {
			system("cls");
			break;
		}
	} while (!(option == 1));
}

// function to update customer's outstanding payment using id (UMAR)
void update_order_customer_id_outstanding_payment_txt(int customer_id_input, string order) {
	ifstream inFile;
	ofstream outFile;
	int customer_id_database;
	string username_database;
	double updated_meal_cost, meal_cost_database, reservation_cost_database, total_cost_database;

	if (order == "3CourseMeal") {
		updated_meal_cost = 69;
	}
	else if (order == "4CourseMeal") {
		updated_meal_cost = 99;
	}
	inFile.open("outstandingpayment.txt");
	outFile.open("tempoutstandingpayment.txt", fstream::app);
	if (!inFile) {
		cout << "An error has occurred. Please try again later." << endl;
	}
	else {
		while (!inFile.eof()) {
			inFile >> customer_id_database >> username_database >> meal_cost_database >> reservation_cost_database >> total_cost_database;
			if (!(customer_id_input == customer_id_database)) {
				outFile << "\n" << customer_id_database << "\t" << username_database << "\t" << meal_cost_database << "\t" << reservation_cost_database << "\t" << total_cost_database;
			}
			else if (customer_id_input == customer_id_database) {
				total_cost_database = total_cost_database - meal_cost_database;
				total_cost_database += updated_meal_cost;
				outFile << "\n" << customer_id_database << "\t" << username_database << "\t" << updated_meal_cost << "\t" << reservation_cost_database << "\t" << total_cost_database;
			}
		}
	}
	inFile.close();
	outFile.close();
	remove("outstandingpayment.txt");
	rename("tempoutstandingpayment.txt", "outstandingpayment.txt");
}

// function to update customer's outstanding payment using username (UMAR)
void update_order_username_outstanding_payment_txt(string username_input, string order) {
	ifstream inFile;
	ofstream outFile;
	int customer_id_database;
	string username_database;
	double updated_meal_cost, meal_cost_database, reservation_cost_database, total_cost_database;

	if (order == "3CourseMeal") {
		updated_meal_cost = 69;
	}
	else if (order == "4CourseMeal") {
		updated_meal_cost = 99;
	}
	inFile.open("outstandingpayment.txt");
	outFile.open("tempoutstandingpayment.txt", fstream::app);
	if (!inFile) {
		cout << "An error has occurred. Please try again later." << endl;
	}
	else {
		while (!inFile.eof()) {
			inFile >> customer_id_database >> username_database >> meal_cost_database >> reservation_cost_database >> total_cost_database;
			if (!(username_input == username_database)) {
				outFile << "\n" << customer_id_database << "\t" << username_database << "\t" << meal_cost_database << "\t" << reservation_cost_database << "\t" << total_cost_database;
			}
			else if (username_input == username_database) {
				total_cost_database = total_cost_database - meal_cost_database;
				total_cost_database += updated_meal_cost;
				outFile << "\n" << customer_id_database << "\t" << username_database << "\t" << updated_meal_cost << "\t" << reservation_cost_database << "\t" << total_cost_database;
			}
		}
	}
	inFile.close();
	outFile.close();
	remove("outstandingpayment.txt");
	rename("tempoutstandingpayment.txt", "outstandingpayment.txt");
}

// function to update customer's order using id (UMAR)
void update_order_customer_id_order_txt() {
	ifstream inFile;
	ofstream outFile;
	int option, customer_id_input, customer_id_database;
	string meal_database, username_database, updated_meal;
	double mealcost_database, updated_meal_cost;
	bool change = false;

	header();
	display_straight_lines();
	cout << "\t  Update Order Using ID" << endl;
	display_straight_lines();
	cout << " Enter Customer's ID to Update Order: ";
	cin >> customer_id_input;
	do {
		system("cls");
		header();
		cout <<  " Enter Customer's ID to Update Order: " << customer_id_input << endl;
		cout << " 1) 3 Course Meal" << endl;
		cout << " 2) 4 Course Meal" << endl;
		cout << " Update Course Ordered To: ";
		cin >> option;
		if (option == 1) {
			updated_meal = "3CourseMeal";
			update_order_customer_id_outstanding_payment_txt(customer_id_input, updated_meal);
			updated_meal_cost = 69;
		}
		else if (option == 2) {
			updated_meal = "4CourseMeal";
			update_order_customer_id_outstanding_payment_txt(customer_id_input, updated_meal);
			updated_meal_cost = 99;
		}
		else {
			cout << "Invalid Option. Please try again." << endl;
		}
	} while (!(option == 1 || option == 2));
	inFile.open("order.txt");
	outFile.open("temporder.txt", fstream::app);
	if (!inFile) {
		cout << "An error has occurred. Please try again later." << endl;
	}
	else {
		while (!inFile.eof()) {
			inFile >> customer_id_database >> username_database >> meal_database >> mealcost_database;
			if (!(customer_id_input == customer_id_database)) {
				outFile << "\n" << customer_id_database << "\t" << username_database << "\t" << meal_database << "\t" << mealcost_database;
			}
			else if (customer_id_input == customer_id_database) {
				outFile << "\n" << customer_id_database << "\t" << username_database << "\t" << updated_meal << "\t" << updated_meal_cost;
				change = true;
			}
		}
	}
	inFile.close();
	outFile.close();
	remove("order.txt");
	rename("temporder.txt", "order.txt");

	if (change == true) {
		display_straight_lines();
		cout << "\t     Order Successfully Updated." << endl;
		display_straight_lines();
	}
	else {
		display_straight_lines();
		cout << "\t\t       Customer's ID not found." << endl;
		display_straight_lines();
	}
	cout << " Returning to Main Menu..." << endl;
	Sleep(2000);
	system("cls");
}

// function to update customer's order using username (UMAR)
void update_order_username_order_txt() {
	ifstream inFile;
	ofstream outFile;
	int option, customer_id_database;
	string username_input, meal_database, username_database, updated_meal;
	double mealcost_database, updated_meal_cost;
	bool change = false;

	header();
	display_straight_lines();
	cout << "\t\t Update Order Using Username" << endl;
	display_straight_lines();
	cout << " Enter Customer's Username to Update Order: ";
	cin >> username_input;
	do {
		system("cls");
		header();
		cout << " Enter Customer's ID to Update Order: " << username_input << endl;
		cout << " 1) 3 Course Meal" << endl;
		cout << " 2) 4 Course Meal" << endl;
		cout << " Update Course Ordered To: ";
		cin >> option;
		if (option == 1) {
			updated_meal = "3CourseMeal";
			update_order_username_outstanding_payment_txt(username_input, updated_meal);
			updated_meal_cost = 69;
		}
		else if (option == 2) {
			updated_meal = "4CourseMeal";
			update_order_username_outstanding_payment_txt(username_input, updated_meal);
			updated_meal_cost = 99;
		}
		else {
			cout << "Invalid Option. Please try again." << endl;
		}
	} while (!(option == 1 || option == 2));
	inFile.open("order.txt");
	outFile.open("temporder.txt", fstream::app);
	if (!inFile) {
		cout << "An error has occurred. Please try again later." << endl;
	}
	else {
		while (!inFile.eof()) {
			inFile >> customer_id_database >> username_database >> meal_database >> mealcost_database;
			if (!(username_input == username_database)) {
				outFile << "\n" << customer_id_database << "\t" << username_database << "\t" << meal_database << "\t" << mealcost_database;
			}
			else if (username_input == username_database) {
				outFile << "\n" << customer_id_database << "\t" << username_database << "\t" << updated_meal << "\t" << updated_meal_cost;
				change = true;
			}
		}
	}
	inFile.close();
	outFile.close();
	remove("order.txt");
	rename("temporder.txt", "order.txt");

	if (change == true) {
		display_straight_lines();
		cout << "\t     Order Successfully Updated." << endl;
		display_straight_lines();
	}
	else {
		display_straight_lines();
		cout << "\t   Customer's username not found." << endl;
		display_straight_lines();
	}
	cout << " Returning to Main Menu..." << endl;
	Sleep(2000);
	system("cls");
}

// function to remove the order cost from outstanding payment.txt (UMAR)
void remove_order_customer_id_outstanding_payment_txt(int customer_id_input) {
	ifstream inFile;
	ofstream outFile;
	int customer_id_database;
	string username_database;
	double updated_meal_cost, meal_cost_database, reservation_cost_database, total_cost_database;

	updated_meal_cost = 0; // sets meal_cost = 0 in outstanding payment
	inFile.open("outstandingpayment.txt");
	outFile.open("tempoutstandingpayment.txt", fstream::app);
	if (!inFile) {
		cout << "An error has occurred. Please try again later." << endl;
	}
	else {
		while (!inFile.eof()) {
			inFile >> customer_id_database >> username_database >> meal_cost_database >> reservation_cost_database >> total_cost_database;
			if (!(customer_id_input == customer_id_database)) {
				outFile << "\n" << customer_id_database << "\t" << username_database << "\t" << meal_cost_database << "\t" << reservation_cost_database << "\t" << total_cost_database;
			}
			else if (customer_id_input == customer_id_database) {
				total_cost_database = total_cost_database - meal_cost_database;
				outFile << "\n" << customer_id_database << "\t" << username_database << "\t" << updated_meal_cost << "\t" << reservation_cost_database << "\t" << total_cost_database;
			}
		}
	}
	inFile.close();
	outFile.close();
	remove("outstandingpayment.txt");
	rename("tempoutstandingpayment.txt", "outstandingpayment.txt");
}

// function to remove the order cost from outstandingpayment.txt using username (UMAR)
void remove_order_username_outstanding_payment_txt(string username) {
	ifstream inFile;
	ofstream outFile;
	int customer_id_database;
	string username_database;
	double updated_meal_cost, meal_cost_database, reservation_cost_database, total_cost_database;

	updated_meal_cost = 0; // sets meal_cost = 0 in outstanding payment
	inFile.open("outstandingpayment.txt");
	outFile.open("tempoutstandingpayment.txt", fstream::app);
	if (!inFile) {
		cout << "An error has occurred. Please try again later." << endl;
	}
	else {
		while (!inFile.eof()) {
			inFile >> customer_id_database >> username_database >> meal_cost_database >> reservation_cost_database >> total_cost_database;
			if (!(username == username_database)) {
				outFile << "\n" << customer_id_database << "\t" << username_database << "\t" << meal_cost_database << "\t" << reservation_cost_database << "\t" << total_cost_database;
			}
			else if (username == username_database) {
				total_cost_database = total_cost_database - meal_cost_database;
				outFile << "\n" << customer_id_database << "\t" << username_database << "\t" << updated_meal_cost << "\t" << reservation_cost_database << "\t" << total_cost_database;
			}
		}
	}
	inFile.close();
	outFile.close();
	remove("outstandingpayment.txt");
	rename("tempoutstandingpayment.txt", "outstandingpayment.txt");
}

// function to remove the order cost from order.txt using username (UMAR)
void remove_order_username_order_txt() {
	ifstream inFile;
	ofstream outFile;
	int option, customer_id_database;
	string  customer_username_input, meal_database, username_database;
	double mealcost_database;
	bool change = false;

	header();
	display_straight_lines();
	cout << "\t    Order Removal Using Username" << endl;
	display_straight_lines();
	cout << " Enter Customer's Username to Remove Order: ";
	cin >> customer_username_input;
	remove_order_username_outstanding_payment_txt(customer_username_input);
	inFile.open("order.txt");
	outFile.open("temporder.txt", fstream::app);
	if (!inFile) {
		cout << "An error has occurred. Please try again later." << endl;
	}
	else {
		while (!inFile.eof()) {
			inFile >> customer_id_database >> username_database >> meal_database >> mealcost_database;
			if (customer_username_input == username_database) {
				change = true;
			}
			if (!(customer_username_input == username_database)) {
				outFile << "\n" << customer_id_database << "\t" << username_database << "\t" << meal_database << "\t" << mealcost_database;
			}
		}
		inFile.close();
		outFile.close();
		remove("order.txt");
		rename("temporder.txt", "order.txt");
	}
	if (change == true) {
		display_straight_lines();
		cout << "\t   Order successfully removed." << endl;
		display_straight_lines();
	}
	else {
		display_straight_lines();
		cout << "\t  Customer's Username not found." << endl;
		display_straight_lines();
	}
	cout << "Returning to Main Menu..." << endl;
	Sleep(2000);
	system("cls");
}

// function to remove the order cost from order.txt using customer id (UMAR)
void remove_order_customer_id_order_txt() {
	ifstream inFile;
	ofstream outFile;
	int option, customer_id_input, customer_id_database;
	string meal_database, username_database;
	double mealcost_database;
	bool change = false;

	header();
	display_straight_lines();
	cout << "\t\t Order Removal Using ID" << endl;
	display_straight_lines();
	cout << " Enter Customer's ID to Remove Order: ";
	cin >> customer_id_input;
	remove_order_customer_id_outstanding_payment_txt(customer_id_input);
	inFile.open("order.txt");
	outFile.open("temporder.txt", fstream::app);
	if (!inFile) {
		cout << "An error has occurred. Please try again later." << endl;
	}
	else {
		while (!inFile.eof()) {
			inFile >> customer_id_database >> username_database >> meal_database >> mealcost_database;
			if (customer_id_input == customer_id_database) {
				change = true;
			}
			if (!(customer_id_input == customer_id_database)) {
				outFile << "\n" << customer_id_database << "\t" << username_database << "\t" << meal_database << "\t" << mealcost_database;
			}
		}
		inFile.close();
		outFile.close();
		remove("order.txt");
		rename("temporder.txt", "order.txt");
	}
	if (change == true) {
		display_straight_lines();
		cout << "\t   Order successfully removed." << endl;
		display_straight_lines();
	}
	else {
		display_straight_lines();
		cout << "\t   Customer's ID not found." << endl;
		display_straight_lines();
	}
	cout << " Returning to Main Menu..." << endl;
	Sleep(2000);
	system("cls");
}

// extended version of company's header (UMAR)
void extended_reservation_company_header() {
	char horizontal_lines = 196, vertical_lines = 179, bottom_lh = 192, top_lh = 218, top_rh = 191, bottom_rh = 217;
	int breadth = 0;
	cout << left;
	for (int x = 1; x <= 5; x++) { // breadth
		if (x != 1 && x != 3 && x != 5) {
			cout << setw(83) << vertical_lines << vertical_lines << endl; // middle length (INCLUDING TEXT)
		}
		else if (x == 3) {
			cout << setw(25) << vertical_lines << setw(58) << "Panteleone's Pizza | #1 Pizza in Town!" << vertical_lines << endl;
		}
		else if (x == 1) {
			cout << top_lh;
			while (breadth <= 81) { // top length
				cout << horizontal_lines;
				breadth++;
			}
			cout << top_rh << endl;
			breadth = 0;
		}
		else if (x == 5) { // bottom length
			cout << bottom_lh;
			while (breadth <= 81) {
				cout << horizontal_lines;
				breadth++;
			}
			cout << bottom_rh << endl;
			breadth = 0;
		}
	}
}

// header to display all customer;s reservation (UMAR)
void staff_display_reservations_header() {
	char horizontal_lines = 196, vertical_lines = 179;
	int breadth = 0;
	cout << left << setw(34) << "\t\t\t\tReservation List" << endl;
	while (breadth < 84) {
		cout << horizontal_lines;
		breadth++;
	}
	breadth = 0;
	cout << endl;
	cout << left << setw(13) << "  Booking ID" << setw(2) << vertical_lines << setw(10) << "User ID"
		<< setw(2) << vertical_lines << setw(16) << "Username" << setw(2) << vertical_lines << setw(18) << "Reservation Date" << setw(2) << vertical_lines << setw(7) << "Adults" << setw(2) << vertical_lines << "Children" << endl;
	while (breadth < 84) {
		cout << horizontal_lines;
		breadth++;
	}
	breadth = 0;
	cout << endl;
}

// functions to display all customer's reservation (UMAR)
void staff_display_reservations() {
	char vertical_lines = 179;
	int option, userID_database, reservationID, reservationID_database, reservationID_input, adults_database, children_database;
	string username_database, dateofreservation_database, password_database, meal_database, username_input;
	double reservationcost_database;
	ifstream inFile;
	ofstream outFile;

	do {
		system("cls");
		extended_reservation_company_header();
		inFile.open("reservationlist.txt");
		if (!inFile) {
			cout << "An error has occurred. Please try again." << endl;
		}
		else {
			staff_display_reservations_header();
			while (!inFile.eof()) {
				inFile >> userID_database >> username_database >> password_database >> dateofreservation_database >> meal_database >> adults_database >> children_database >> reservationcost_database >> reservationID_database;
				cout << "  " << left << setw(11) << reservationID_database << setw(2) << vertical_lines << setw(10) << userID_database << setw(2) << vertical_lines << setw(16) << username_database << setw(2) << vertical_lines << setw(18) << dateofreservation_database << setw(2) << vertical_lines << setw(7) << adults_database << setw(2) << vertical_lines << children_database << endl;
			}
		}
		inFile.close();
		cout << "\n\n1) Return to Main Menu" << endl;
		cout << "Option: ";
		cin >> option;
		if (option != 1) {
			cout << "Invalid Option. Please try again." << endl;
			Sleep(2000);
			system("cls");
		}
		else {
			system("cls");
			break;
		}
	} while (!(option == 1));
}

// function to remove booking cost in outstandingpayment.txt using customer id (UMAR)
void remove_reservation_customer_id_outstanding_payment_txt(int customer_ID_input) {
	ifstream inFile;
	ofstream outFile;
	int customer_id_database;
	string username_database;
	double updated_reservation_cost, meal_cost_database, reservation_cost_database, total_cost_database;

	updated_reservation_cost = 0; // sets meal_cost = 0 in outstanding payment
	inFile.open("outstandingpayment.txt");
	outFile.open("tempoutstandingpayment.txt", fstream::app);
	if (!inFile) {
		cout << "An error has occurred. Please try again later." << endl;
	}
	else {
		while (!inFile.eof()) {
			inFile >> customer_id_database >> username_database >> meal_cost_database >> reservation_cost_database >> total_cost_database;
			if (!(customer_ID_input == customer_id_database)) {
				outFile << "\n" << customer_id_database << "\t" << username_database << "\t" << meal_cost_database << "\t" << reservation_cost_database << "\t" << total_cost_database;
			}
			else if (customer_ID_input == customer_id_database) {
				total_cost_database = total_cost_database - reservation_cost_database;
				outFile << "\n" << customer_id_database << "\t" << username_database << "\t" << meal_cost_database << "\t" << updated_reservation_cost << "\t" << total_cost_database;
			}
		}
	}
	inFile.close();
	outFile.close();
	remove("outstandingpayment.txt");
	rename("tempoutstandingpayment.txt", "outstandingpayment.txt");
}

// function to remove customer's reservation in reservationlist.txt using customer id (UMAR)
void remove_reservation_customer_id_reservation_list_txt() {
	ifstream inFile;
	ofstream outFile;
	int option, userID_database, reservationID, reservationID_database, reservationID_input, adults_database, children_database, customer_ID_input;
	string username_database, dateofreservation_database, password_database, meal_database;
	double reservationcost_database;
	bool change = false;

	header();
	display_straight_lines();
	cout << "\t\tReservation Removal Using ID" << endl;
	display_straight_lines();
	cout << " Enter Customer's ID to Remove Order: ";
	cin >> customer_ID_input;
	remove_reservation_customer_id_outstanding_payment_txt(customer_ID_input);
	inFile.open("reservationlist.txt");
	outFile.open("tempreservationlist.txt", fstream::app);
	if (!inFile) {
		cout << "An error has occurred. Please try again later." << endl;
	}
	else {
		while (!inFile.eof()) {
			inFile >> userID_database >> username_database >> password_database >> dateofreservation_database >> meal_database >> adults_database >> children_database >> reservationcost_database >> reservationID_database;
			if (customer_ID_input == userID_database) {
				change = true;
			}
			if (!(customer_ID_input == userID_database)) {
				outFile << "\n" << userID_database << "\t" << username_database << "\t" << password_database << "\t" << dateofreservation_database << "\t" << meal_database << "\t" << adults_database << "\t" << children_database << "\t" << reservationcost_database << "\t" << reservationID_database;
			}
		}
		inFile.close();
		outFile.close();
		remove("reservationlist.txt");
		rename("tempreservationlist.txt", "reservationlist.txt");
	}
	if (change == true) {
		display_straight_lines();
		cout << "\t   Reservation successfully removed." << endl;
		display_straight_lines();
	}
	else {
		display_straight_lines();
		cout << "\t   Customer's ID not found." << endl;
		display_straight_lines();
	}
	Sleep(2000);
	system("cls");
}

// function to remove booking cost in reservationlist.txt using username (UMAR)
void remove_reservation_username_outstanding_payment_txt(string customer_username_input) {
	ifstream inFile;
	ofstream outFile;
	int customer_id_database;
	string username_database;
	double updated_reservation_cost, meal_cost_database, reservation_cost_database, total_cost_database;

	updated_reservation_cost = 0; // sets meal_cost = 0 in outstanding payment
	inFile.open("outstandingpayment.txt");
	outFile.open("tempoutstandingpayment.txt", fstream::app);
	if (!inFile) {
		cout << "An error has occurred. Please try again later." << endl;
	}
	else {
		while (!inFile.eof()) {
			inFile >> customer_id_database >> username_database >> meal_cost_database >> reservation_cost_database >> total_cost_database;
			if (!(customer_username_input == username_database)) {
				outFile << "\n" << customer_id_database << "\t" << username_database << "\t" << meal_cost_database << "\t" << reservation_cost_database << "\t" << total_cost_database;
			}
			else if (customer_username_input == username_database) {
				total_cost_database = total_cost_database - reservation_cost_database;
				outFile << "\n" << customer_id_database << "\t" << username_database << "\t" << meal_cost_database << "\t" << updated_reservation_cost << "\t" << total_cost_database;
			}
		}
	}
	inFile.close();
	outFile.close();
	remove("outstandingpayment.txt");
	rename("tempoutstandingpayment.txt", "outstandingpayment.txt");
}

// function to remove customer's reservation in reservationlist.txt using username (UMAR)
void remove_reservation_username_reservation_list_txt() {
	ifstream inFile;
	ofstream outFile;
	int option, userID_database, reservationID, reservationID_database, reservationID_input, adults_database, children_database;
	string username_database, dateofreservation_database, password_database, meal_database, customer_username_input;
	double reservationcost_database;
	bool change = false;

	header();
	display_straight_lines();
	cout << "\tReservation Removal Using Username" << endl;
	display_straight_lines();
	cout << " Enter Customer's Username to Remove Order: ";
	cin >> customer_username_input;
	remove_reservation_username_outstanding_payment_txt(customer_username_input);
	inFile.open("reservationlist.txt");
	outFile.open("tempreservationlist.txt", fstream::app);
	if (!inFile) {
		cout << "An error has occurred. Please try again later." << endl;
	}
	else {
		while (!inFile.eof()) {
			inFile >> userID_database >> username_database >> password_database >> dateofreservation_database >> meal_database >> adults_database >> children_database >> reservationcost_database >> reservationID_database;
			if (customer_username_input == username_database) {
				change = true;
			}
			if (!(customer_username_input == username_database)) {
				outFile << "\n" << userID_database << "\t" << username_database << "\t" << password_database << "\t" << dateofreservation_database << "\t" << meal_database << "\t" << adults_database << "\t" << children_database << "\t" << reservationcost_database << "\t" << reservationID_database;
			}
		}
		inFile.close();
		outFile.close();
		remove("reservationlist.txt");
		rename("tempreservationlist.txt", "reservationlist.txt");
	}
	if (change == true) {
		display_straight_lines();
		cout << "\t   Reservation successfully removed." << endl;
		display_straight_lines();
	}
	else {
		display_straight_lines();
		cout << "\t    Customer's username not found." << endl;
		display_straight_lines();
	}
	cout << "Returning to Main Menu..." << endl;
	Sleep(2000);
	system("cls");

}

// staff menu relating to reservation (UMAR)
void staff_check_reservation() {
	int option;
	
	header();
	display_straight_lines();
	cout << "\t\t Admin Reservation Menu" << endl;
	display_straight_lines();
	cout << " 1) Check All Reservations" << endl;
	cout << " 2) Remove Reservations" << endl;
	cout << " 3) Return to Main Menu" << endl;
	cout << " Option: ";
	cin >> option;
	if (option == 1) {
		system("cls");
		staff_display_reservations();
	}
	else if (option == 2) {
		system("cls");
		header();
		display_straight_lines();
		cout << "\t\t Reservation Removal Menu" << endl;
		display_straight_lines();
		cout << " 1) Remove Reservation Using Customer's ID" << endl;
		cout << " 2) Remove Reservation Using Username" << endl;
		cout << " 3) Return to Main Menu" << endl;
		cout << " Option: ";
		cin >> option;
		if (option == 1) {
			system("cls");
			remove_reservation_customer_id_reservation_list_txt(); // DONE
		}
		else if (option == 2) {
			system("cls");
			remove_reservation_username_reservation_list_txt(); // DONE
		}
		else {
			system("cls");
		}
	}
	else if (option == 3) {
		system("cls");
	}
}

// function to display line beneath the paid payment list (UMAR)
void paid_payments_horizontal_line() {
	char horizontal_lines = 196;
	int breadth = 0;
	while (breadth < 83) {
		cout << horizontal_lines;
		breadth++;
	}
	breadth = 0;
}

// header function to display all paid payments made by customers (UMAR)
void staff_paid_payments_header() {
	char horizontal_lines = 196, vertical_lines = 179;
	int breadth = 0;
	cout << left << setw(34) << "\t\t\t\tPaid Payments" << endl;
	while (breadth < 83) {
		cout << horizontal_lines;
		breadth++;
	}
	breadth = 0;
	cout << endl;
	cout << left << setw(10) << "  User ID" << setw(2) << vertical_lines << setw(15) << "Username"
		<< setw(2) << vertical_lines << setw(18) << "Course Price ($)" << setw(2) << vertical_lines << setw(17) << "Booking Cost ($)" << setw(2) << vertical_lines << "Total Cost ($)" << endl;
	while (breadth < 83) {
		cout << horizontal_lines;
		breadth++;
	}
	breadth = 0;
	cout << endl;
}

// extended version of company's header (UMAR)
void extended_paid_payments_company_header() {
	char horizontal_lines = 196, vertical_lines = 179, bottom_lh = 192, top_lh = 218, top_rh = 191, bottom_rh = 217;
	int breadth = 0;
	cout << left;
	for (int x = 1; x <= 5; x++) { // breadth
		if (x != 1 && x != 3 && x != 5) {
			cout << setw(82) << vertical_lines << vertical_lines << endl; // middle length (INCLUDING TEXT)
		}
		else if (x == 3) {
			cout << setw(23) << vertical_lines << setw(59) << "Panteleone's Pizza | #1 Pizza in Town!" << vertical_lines << endl;
		}
		else if (x == 1) {
			cout << top_lh;
			while (breadth <= 80) { // top length
				cout << horizontal_lines;
				breadth++;
			}
			cout << top_rh << endl;
			breadth = 0;
		}
		else if (x == 5) { // bottom length
			cout << bottom_lh;
			while (breadth <= 80) {
				cout << horizontal_lines;
				breadth++;
			}
			cout << bottom_rh << endl;
			breadth = 0;
		}
	}
}

// function to filter paid payments using username (UMAR)
void display_staff_paid_payments_filter_username() {
	char vertical_lines = 179;
	ifstream inFile;
	int option, customer_id_database;
	string username_database, username_input;
	double updated_meal_cost, meal_cost_database, reservation_cost_database, total_cost_database;
	bool available = false;
	extended_paid_payments_company_header();
	staff_paid_payments_header();
	cout << "\n\n\n\n\n\nEnter Username to Find: ";
	cin >> username_input;
	do {
		system("cls");
		extended_paid_payments_company_header();
		inFile.open("paidpayments.txt");
		if (!inFile) {
			cout << "An error has occurred. Please try again later." << endl;
		}
		else {
			staff_paid_payments_header();
			while (!inFile.eof()) {
				inFile >> customer_id_database >> username_database >> meal_cost_database >> reservation_cost_database >> total_cost_database;
				if (username_input == username_database) {
					available = true;
					cout << "  " << left << setw(8) << customer_id_database << setw(2) << vertical_lines << setw(15) << username_database
						<< setw(2) << vertical_lines << setw(18) << fixed << setprecision(2) << meal_cost_database << setw(2) << vertical_lines << setw(17) << reservation_cost_database << setw(2) << vertical_lines << total_cost_database << endl;
				}
			}
			if (available == false) {
				cout << "\n\t\t\tCustomer's Username not found.\n\n";
			}
			paid_payments_horizontal_line();
		}
		inFile.close();
		cout << "\n\n1) Return to Main Menu" << endl;
		cout << "Option: ";
		cin >> option;
		if (option != 1 || option == 1) {
			system("cls");
			break;
		}
	} while (option != 1);
}

// fucntion to filter paud payments using customer's id (UMAR)
void display_staff_paid_payments_filter_id() {
	char vertical_lines = 179;
	ifstream inFile;
	int option, customer_id_database, customer_ID_input;
	string username_database;
	double updated_meal_cost, meal_cost_database, reservation_cost_database, total_cost_database;
	bool available = false;
	extended_paid_payments_company_header();
	staff_paid_payments_header();
	cout << "\n\n\n\n\n\nEnter Customer's ID to Find: ";
	cin >> customer_ID_input;
	do {
		system("cls");
		extended_paid_payments_company_header();
		inFile.open("paidpayments.txt");
		if (!inFile) {
			cout << "An error has occurred. Please try again later." << endl;
		}
		else {
			staff_paid_payments_header();
			while (!inFile.eof()) {
				inFile >> customer_id_database >> username_database >> meal_cost_database >> reservation_cost_database >> total_cost_database;
				if (customer_ID_input == customer_id_database) {
					available = true;
					cout << "  " << left << setw(8) << customer_id_database << setw(2) << vertical_lines << setw(15) << username_database
						<< setw(2) << vertical_lines << setw(18) << fixed << setprecision(2) << meal_cost_database << setw(2) << vertical_lines << setw(17) << reservation_cost_database << setw(2) << vertical_lines << total_cost_database << endl;
				}
			}
			if (available == false) {
				cout << "\n\t\t\tCustomer's ID not found.\n\n";
			}
			paid_payments_horizontal_line();
		}
		inFile.close();
		cout << "\n\n1) Return to Main Menu" << endl;
		cout << "Option: ";
		cin >> option;
		if (option != 1 || option == 1) {
			system("cls");
			break;
		}
	} while (option != 1);
}

// function to display all paid payments (UMAR)
void display_staff_paid_payments() {
	char vertical_lines = 179;
	ifstream inFile;
	int option, customer_id_database;
	string username_database;
	double updated_meal_cost, meal_cost_database, reservation_cost_database, total_cost_database, sum_total_cost_from_database = 0, sum_booking_cost_from_database = 0, sum_meal_cost_from_database = 0;
	int numberofpayments = 0;
	double average_payments;
	double highest_payment = -9999;
	string highest_patron;

	do {
		extended_paid_payments_company_header();
		inFile.open("paidpayments.txt");
		if (!inFile) {
			cout << "An error has occurred. Please try again later." << endl;
		}
		else {
			staff_paid_payments_header();
			while (!inFile.eof()) {
				inFile >> customer_id_database >> username_database >> meal_cost_database >> reservation_cost_database >> total_cost_database;
				cout << "  " << left << setw(8) << customer_id_database << setw(2) << vertical_lines << setw(15) << username_database 
					<< setw(2) << vertical_lines << setw(18) << fixed << setprecision(2)  << meal_cost_database << setw(2) << vertical_lines << setw(17) << reservation_cost_database << setw(2) << vertical_lines << total_cost_database << endl;
				sum_total_cost_from_database += total_cost_database;
				numberofpayments++;
				sum_booking_cost_from_database += reservation_cost_database;
				sum_meal_cost_from_database += meal_cost_database;
				if (total_cost_database > highest_payment) {
					highest_payment = total_cost_database;
					highest_patron = username_database;
				}
			}
			paid_payments_horizontal_line();
		}
		inFile.close();
		
		average_payments = sum_total_cost_from_database / numberofpayments;
		cout << endl;
		cout << "\t\t\t     Descriptive Statistics" << endl;
		paid_payments_horizontal_line();
		cout << endl;
		cout << " Sum of Booking Payments: $" << sum_booking_cost_from_database << endl;
		cout << " Sum of Course Ordered Payments $:" << sum_meal_cost_from_database << endl;
		cout << " Sum of Total Payments: $" << sum_total_cost_from_database << endl;
		cout << " Average Payments: $" << average_payments << endl; 
		cout << " Highest Payment: $" << highest_payment << endl;
		cout << " Patron's Username with Highest Payment: " << highest_patron << endl;
		paid_payments_horizontal_line();
		cout << endl;
		cout << "\n 1) Return to Main Menu" << endl;
		cout << " 2) Filter by Username" << endl;
		cout << " 3) Filter by Customer ID" << endl;
 		cout << " Option: ";
		cin >> option;
		if (option == 1) {
			system("cls");
			break;
		}
		else if (option == 2) {
			system("cls");
			display_staff_paid_payments_filter_username();
			break;
		}
		else if (option == 3) {
			system("cls");
			display_staff_paid_payments_filter_id();
			break;
		}
		else {
			cout << "Invalid Option. Please try again." << endl;
			Sleep(2000);
			system("cls");
		}
	} while (!(option == 1 || option == 2 || option == 3));
}

// function to display staff's main menu (UMAR)
void staffmainmenu() {
	int option;
	bool logout = false;
	do {
		header();
		cout << "    Staff Username: " << staff_username << "     " << " | \tStaff ID: " << staffID << endl;
		display_straight_lines();
		cout << "\t\t\tMain Menu" << endl;
		display_straight_lines();
		cout << " 1) Admin Reservation Menu" << endl;
		cout << " 2) Admin Order Menu" << endl;
		cout << " 3) Check Completed Payments" << endl;
		cout << " 9) Log out" << endl;
		cout << " Option: ";
		cin >> option;

		switch (option) {
		case 1:
			system("cls");
			header();
			display_straight_lines();
			cout << "\t\t    Option Confirmation" << endl;
			display_straight_lines();
			cout << " Are you sure you want to access this menu?" << endl;
			cout << " 1) Yes" << endl;
			cout << " 2) No" << endl;
			cout << "\n Option: ";
			cin >> option;
			if (option == 1) {
				system("cls");
				staff_check_reservation();
				break;
			}
			else if (option == 2) {
				system("cls");
				break; // or mainmenu()
			}
		case 2:
			system("cls");
			header();
			display_straight_lines();
			cout << "\t\t    Option Confirmation" << endl;
			display_straight_lines();
			cout << " Are you sure you want to access this menu?" << endl;
			cout << " 1) Yes" << endl;
			cout << " 2) No" << endl;
			cout << "\n Option: ";
			cin >> option;
			if (option == 1) {
				system("cls");
				staff_check_order();
				break;
			}
			else if (option == 2) {
				system("cls");
				break; // or mainmenu()
			}
		case 3:
			system("cls");
			header();
			display_straight_lines();
			cout << "\t\t    Option Confirmation" << endl;
			display_straight_lines();
			cout << " Are you sure you want to access this menu?" << endl;
			cout << " 1) Yes" << endl;
			cout << " 2) No" << endl;
			cout << "\n Option: ";
			cin >> option;
			if (option == 1) {
				system("cls");
				display_staff_paid_payments();
				break;
			}
			else if (option == 2) {
				system("cls");
				break; // or mainmenu()
			}
		case 9: 
			system("cls");
			header();
			display_straight_lines();
			cout << "\t\t Logging out.. Please wait" << endl;
			display_straight_lines();
			logout = true;
			Sleep(1500);
			system("cls");
			break;
		default:
			cout << "Invalid option. Please try again!" << endl;
			Sleep(2000);
			system("cls");
			break;
		}
	} while (!(logout == true));
}

// function to display customer's main menu (UMAR)
void mainmenu() {
	int option;
	bool logout = false;
	do {
		header();
		cout << " Customer Username: " << username << " | User ID: " << customerID << " | Credits: " << credits << endl;
		display_straight_lines();
		cout << "\t\t\tMain Menu" << endl;
		display_straight_lines();
		cout << " 1) Book your reservation" << endl;
		cout << " 2) Check your reservation" << endl;
		cout << " 3) Cancel your reservation" << endl;
		cout << " 4) Order your food" << endl;
		cout << " 5) Payment" << endl;
		cout << " 9) Log out" << endl;
		cout << "\n Option: ";
		cin >> option;

		switch (option) {
		case 1:
			system("cls");
			header();
			display_straight_lines();
			cout << "\t\t    Option Confirmation" << endl;
			display_straight_lines();
			cout << " Are you sure you want to access this menu?" << endl;
			cout << " 1) Yes" << endl;
			cout << " 2) No" << endl;
			cout << "\n Option: ";
			cin >> option;
			if (option == 1) {
				system("cls");
				book_reservation();
				break;
			}
			else if (option == 2) {

				system("cls");
				break; // or mainmenu()
			}
		case 2:
			system("cls");
			header();
			display_straight_lines();
			cout << "\t\t    Option Confirmation" << endl;
			display_straight_lines();
			cout << " Are you sure you want to access this menu?" << endl;
			cout << " 1) Yes" << endl;
			cout << " 2) No" << endl;
			cout << "\n Option: ";
			cin >> option;
			if (option == 1) {
				system("cls");
				check_reservation();
				break;
			}
			else if (option == 2) {

				system("cls");
				break; // or mainmenu()
			}
		case 3:
			system("cls");
			header();
			display_straight_lines();
			cout << "\t\t    Option Confirmation" << endl;
			display_straight_lines();
			cout << " Are you sure you want to access this menu?" << endl;
			cout << " 1) Yes" << endl;
			cout << " 2) No" << endl;
			cout << "\n Option: ";
			cin >> option;
			if (option == 1) {
				system("cls");
				cancel_reservation();
				break;
			}
			else if (option == 2) {

				system("cls");
				break; // or mainmenu()
			}
		case 4:
			system("cls");
			header();
			display_straight_lines();
			cout << "\t\t    Option Confirmation" << endl;
			display_straight_lines();
			cout << " Are you sure you want to access this menu?" << endl;
			cout << " 1) Yes" << endl;
			cout << " 2) No" << endl;
			cout << " \n Option: ";
			cin >> option;
			if (option == 1) {
				system("cls");
				order_menu();
				break;
			}
			else if (option == 2) {

				system("cls");
				break; // or mainmenu()
			}
		case 5:
			system("cls");
			header();
			display_straight_lines();
			cout << "\t\t    Option Confirmation" << endl;
			display_straight_lines();
			cout << " Are you sure you want to access this menu?" << endl;
			cout << " 1) Yes" << endl;
			cout << " 2) No" << endl;
			cout << "\n Option: ";
			cin >> option;
			if (option == 1) {
				system("cls");
				payment();
				break;
			}
			else if (option == 2) {

				system("cls");
				break; // or mainmenu()
			}
		case 9:
			system("cls");
			header();
			display_straight_lines();
			cout << "\t\t Logging out.. Please wait" << endl;
			display_straight_lines();
			logout = true;
			Sleep(1500);
			system("cls");
			break;
		default:
			cout << "Invalid option. Please try again!" << endl;
			Sleep(2000);
			system("cls");
			break;
		}
	} while (!(logout == true));
}