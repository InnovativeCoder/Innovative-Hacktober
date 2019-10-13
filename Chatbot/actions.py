# This files contains your custom actions which can be used to run
# custom Python code.
#
# See this guide on how to implement these action:
# https://rasa.com/docs/rasa/core/actions/#custom-actions/
# This is a simple example for a custom action which utters "Hello World!"
import re
from typing import Any, Dict, List, Optional, Text, Union

from rasa_sdk import Action, Tracker
from rasa_sdk.executor import CollectingDispatcher
from rasa_sdk.forms import REQUESTED_SLOT, FormAction


class ActionRegisterUser(FormAction):

    def name(self):
        print("Inside name:")
        return "register_form"


    @staticmethod
    def required_slots(tracker: Tracker) -> List[Text]:
        print("Inside required_slots:")    
        return ["name","email","number"]



    def validate_name(self, value: Text, dispatcher: CollectingDispatcher, tracker: Tracker, domain: Dict[Text, Any]) -> List[Dict]:
        print("Inside validate function")
        print("Inside validate function name ",value)

        name = value
        if isinstance(value,str):
            return {"name": value}
            print("inside validate name")
        else:
            dispatcher.utter_template("utter_wrong_name", tracker)
            print("inside invalidate name")
            return {"name": None}
    
    @staticmethod
    def isValidEmail(email):
        if len(email) > 7:
            if re.match("^.+@([?)[a-zA-Z0-9-.]+.([a-zA-Z]{2,3}|[0-9]{1,3})(]?)$", email) != None:
                return True
        return False
    def validate_email(self, value, dispatcher, tracker, domain):
        """Check to see if an email entity was actually picked up by duckling."""
        print("Inside validate function of email")
        print("Inside validate function of email ",value)
        # is_valid = validate_email(value)
        # if(isValidEmail(value)):
        # r"(^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$)"if re.match(r'\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,}\b',value):
        if re.match(r"[a-zA-Z0-9_.+-]+@[a-zA-Z]+\.[^@]+", value):
            return {"email": value}
            print("inside validate email")   
            # entity was picked up, validate slot
        else:
            # no entity was picked up, we want to ask again
            print("inside in validate email")
            dispatcher.utter_template("utter_wrong_email", tracker)
            return {"email": None}
            
    def validate_number(self, value, dispatcher, tracker, domain):
        """Check to see if an email entity was actually picked up by duckling."""
        print("Inside validate function of number")
        print("Inside validate function of number ",value)
        if re.match(r"^(?:(?:\+|0{0,2})91(\s*[\-]\s*)?|[0]?)?[6789]\d{9}$",str(value)):
            # entity was picked up, validate slot
            print("inside validate number")
            return {"number": value}
        else:
            # no entity was picked up, we want to ask again\
            print("inside invalidate number")
            dispatcher.utter_template("utter_wrong_number", tracker)
            return {"number": None}
    
    


    def slot_mappings(self) -> Dict[Text, Union[Dict, List[Dict]]]:
        """A dictionary to map required slots to
            - an extracted entity
            - intent: value pairs
            - a whole message
            or a list of them, where a first match will be picked"""

        print("slot mapping")

        return {
            "name": self.from_entity(entity="name", intent=["user_info"]),
            "email": [
                self.from_entity(entity="email"),
                self.from_text(intent="user_info"),
                ],
            "number": [
                self.from_entity(entity="number"),
                self.from_text(intent="user_info"),
                ]    
        }
    
    
    def submit(self, dispatcher: CollectingDispatcher, tracker: Tracker,domain: Dict[Text, Any]):
        dispatcher.utter_template("utter_submit", tracker)
        print("Inside submit:")
        return []

