# aws_dynamodb

1. Compile and run create_table.cpp to create AWS DynamoDB table 'Teams'

	create_table eu-west-1

2. Compile and run put_item.cpp

	put_item Teams 0 Champion=false Country=Germany League=Bundesliga Name=Bayern Rating=0.98\n";
	
	Run more times to POST more items to database
	
3. Compile and run get_item.cpp 

	get_item Teams 0
	
	to get Team with id = 0
	
4. You can also access items in the database using the AWS API Gateway link below


	GET API web link:
	https://hrxbtdokf0.execute-api.eu-west-1.amazonaws.com/prod/get-team?id=0

	id range of values {0 - 8}


