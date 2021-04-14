import json
import boto3

print ('Loading function')

def lambda_handler(event, context):
   
   teamId = event['queryStringParameters']['id']


   teamResponse = {}
   teamResponse['id'] = teamId
   #teamResponse['message'] = 'Hello from Lambda land updated again back to orig'

   
   client = boto3.resource("dynamodb")
   table = client.Table("Teams")
   teams = table.scan()['Items']

   
   teamInfo = [team for team in teams if team['id'] == str(teamId)]
   
   subs = {}
   
   for item in teamInfo:
      for key in item:
         if key != 'id':
            teamResponse[key] = str(item[key])

   
   responseObject = {}
   responseObject['statusCode'] = 200
   responseObject['headers'] = {}
   responseObject['headers']['Content-Type'] = 'application/json'
   responseObject['body'] = json.dumps(teamResponse)

   return responseObject

