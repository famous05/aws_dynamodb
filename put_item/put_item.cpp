/*
Copyright 2021 Osarobo Famous Okhuahesogie, famous.osarobo@gmail.com
*/

#include <aws/core/Aws.h>
#include <aws/core/utils/Outcome.h> 
#include <aws/dynamodb/DynamoDBClient.h>
#include <aws/dynamodb/model/AttributeDefinition.h>
#include <aws/dynamodb/model/PutItemRequest.h>
#include <aws/dynamodb/model/PutItemResult.h>
#include <iostream>


/**
* Put an item in a DynamoDB table.
*
* Takes the name of the table, primary key "id" and associated key value pairs
*/
int main(int argc, char** argv)
{
    const std::string USAGE = \
        "Usage:\n"
        "    put_item <table> <id> [field=value ...]\n\n"
        "Where:\n"
        "    table    - the table to put the item in.\n"
        "    id     - a id to add to the table. If the id already\n"
        "               exists, its entry will be updated.\n\n"
        "Additional fields can be added by appending them to the end of the\n"
        "input.\n\n"
        "Example:\n"
        "    put_item Teams 7 Champion=false Country=Germany League=Bundesliga Name=Bayern Rating=0.98\n";

    if (argc < 3)
    {
        std::cout << USAGE;
        return 1;
    }

    Aws::SDKOptions options;

    Aws::InitAPI(options);
    {
        const Aws::String table(argv[1]);
        const Aws::String id(argv[2]);

        Aws::Client::ClientConfiguration clientConfig;
        Aws::DynamoDB::DynamoDBClient dynamoClient(clientConfig);

        Aws::DynamoDB::Model::PutItemRequest pir;
        pir.SetTableName(table);

        Aws::DynamoDB::Model::AttributeValue av;
        av.SetS(id);
        pir.AddItem("id", av);

        for (int x = 3; x < argc; x++)
        {
            const Aws::String arg(argv[x]);
            const Aws::Vector<Aws::String>& flds = Aws::Utils::StringUtils::Split(arg, '=');
            if (flds.size() == 2)
            {
                Aws::DynamoDB::Model::AttributeValue val;
                val.SetS(flds[1]);
                pir.AddItem(flds[0], val);
            }
            else
            {
                std::cout << "Invalid argument: " << arg << std::endl << USAGE;
                return 1;
            }
        }

        const Aws::DynamoDB::Model::PutItemOutcome result = dynamoClient.PutItem(pir);
        if (!result.IsSuccess())
        {
            std::cout << result.GetError().GetMessage() << std::endl;
            return 1;
        }
        std::cout << "Done!" << std::endl;
    }
    Aws::ShutdownAPI(options);
    return 0;
}
