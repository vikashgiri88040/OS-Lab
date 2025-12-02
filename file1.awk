BEGIN{
	print "Hello";
}

{
	if((45000<$5 && $5<65000)&&(2010<$4 && $4<2019)&&($3!="January")&&($3!="December")){
		print $0;
	}
}

END{
	print "Bye";
}
