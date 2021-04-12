Action()
{

	web_reg_save_param_ex(
		"ParamName=UsSession",
		"LB=\" name=\"userSession\" value=\"",
		"RB=\"/>",
		"Ordinal=1",
		LAST);
	
	web_url("WebTours",
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);


	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={UsSession}", ENDITEM, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=0", ENDITEM, 
		"Name=login.y", "Value=0", ENDITEM, 
		LAST);

	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_reg_save_param_ex(
		"ParamName=Cost",
		"LB=<td align=\"center\">$ ",
		"RB=</TD></TR>",
		"Ordinal=All",
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=OFlight",
		"LB=name=\"outboundFlight\" value=\"",
		"RB=\"",
		"Ordinal=All",
		LAST);

	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={DepartCity}", ENDITEM, 
		"Name=departDate", "Value={DateDepart}", ENDITEM, 
		"Name=arrive", "Value={ArriveCity}", ENDITEM, 
		"Name=returnDate", "Value={DateArrive}", ENDITEM, 
		"Name=numPassengers", "Value={NumPas}", ENDITEM, 
		"Name=seatPref", "Value={SeatPref}", ENDITEM, 
		"Name=seatType", "Value={SeatType}", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=75", ENDITEM, 
		"Name=findFlights.y", "Value=6", ENDITEM, 
		LAST);

/*	lr_save_int(atoi(lr_eval_string("{Cost_1}"),"a"));
	lr_save_int(atoi(lr_eval_string("{Cost_2}"),"b"));
	lr_save_int(atoi(lr_eval_string("{Cost_3}"),"c"));
	lr_save_int(atoi(lr_eval_string("{Cost_4}"),"d"));
	*/
	if (atoi(lr_eval_string("{Cost_1}"))%2==0)
	{
		lr_save_string(lr_eval_string("{OFlight_1}"),"OFli");}
	else {
	if (atoi(lr_eval_string("{Cost_2}"))%2==0)
	{lr_save_string(lr_eval_string("{OFlight_2}"),"OFli");}
	else{
	if (atoi(lr_eval_string("{Cost_3}"))%2==0)
	{lr_save_string(lr_eval_string("{OFlight_3}"),"OFli");}
	else {
	if (atoi(lr_eval_string("{Cost_4}"))%2==0)
	{lr_save_string(lr_eval_string("{OFlight_4}"),"OFli");}
	else 
	// if (a%2 !=0 || b%2 !=0 || c%2 !=0 || d%2 !=0)
	{lr_exit(LR_EXIT_VUSER, LR_AUTO);}
	}}}
	
		
 		lr_output_message("%s",lr_eval_string("{OFli}"));
	
	web_submit_data("reservations.pl_2", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={OFli}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=reserveFlights.x", "Value=62", ENDITEM, 
		"Name=reserveFlights.y", "Value=7", ENDITEM, 
		LAST);
	
	
	web_submit_data("reservations.pl_3", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value=Jojo", ENDITEM, 
		"Name=lastName", "Value=Bean", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=pass1", "Value=Jojo Bean", ENDITEM, 
		"Name=creditCard", "Value=", ENDITEM, 
		"Name=expDate", "Value=", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=outboundFlight", "Value={OFli}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=23", ENDITEM, 
		"Name=buyFlights.y", "Value=8", ENDITEM, 
		LAST);

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}