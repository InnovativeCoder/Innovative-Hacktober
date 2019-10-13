## happy path
* greet
  - utter_greet

## moody
* mood_great
  - utter_happy

## sad path 1
* greet
  - utter_greet

## moody1
* mood_unhappy
  - utter_cheer_up
  - utter_did_that_help

## moody2
* affirm
  - utter_happy

## say goodbye
* goodbye
  - utter_goodbye

## register form story
* register_request
    - register_form
    - form{"name":"register_form"}
    - form{"name":"null"}
    - utter_slot_values

## New Story

* register_request
    - register_form
    - slot{"requested_slot":"name"}
* user_info{"name":"sanjay"}
    - register_form
    - slot{"name":"sanjay"}
    - slot{"requested_slot":"email"}
* user_info{"email":"arbakhna971@gmail.com"}
    - slot{"email":"arbakhna971@gmail.com"}
    - register_form
    - slot{"email":"arbakhna971@gmail.com"}
    - slot{"requested_slot":"number"}
* user_info{"number":888212248321}
    - slot{"number":888212248321}
    - register_form
    - slot{"number":null}
    - slot{"requested_slot":"number"}
* user_info{"number":8574856885}
    - slot{"number":8574856885}
    - register_form
    - slot{"number":8574856885}
    - slot{"requested_slot":null}
    - utter_slot_values
