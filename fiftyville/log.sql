-- Keep a log of any SQL queries you execute as you solve the mystery.


SELECT description FROM crime_scene_reports
WHERE month = "7"
AND day = "28"
AND street = "Humphrey Street";

--Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
--Interviews were conducted today with three witnesses who were present at the time
-- each of their interview transcripts mentions the bakery. |
--Littering took place at 16:36. No known witnesses.


SELECT name, transcript FROM interviews
WHERE month = 7
AND day = 28;

--RUTH- thief gets into car within 10mins of theft, view cctv footage (10.15 - 1025am)
--EUGENE- witness recognises thief, saw him withdrawing money at Leggett St ATM in the morn b4 theft.
--RAYMOND- Plans to take earliest flight out TMR
--RAYMOND- Ticket purchased by person thief was talking to on the phone when leaving (CALL DURATION < 1min)


----ruth, eugene, raymond are the 3 witnesses, BakeRy belongs to EMMA-----


--LIST OF LICENSE PLATES AT SAID TIME AND LOC
SELECT activity, license_plate FROM bakery_security_logs
WHERE month = 7
AND day = 28
AND year = 2021
AND hour = 10
AND minute >= 15
AND minute <= 25
ORDER BY bakery_security_logs.minute;


--LIST OF PPL that matches license plate at crime scene
SELECT DISTINCT name, id, people.passport_number, phone_number FROM people, passengers
WHERE people.license_plate IN(SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND year = 2021 AND hour = 10 AND minute >= 15 AND minute <= 25);



--list of acc no. and amount withdraw on said date and location
SELECT account_number, amount FROM atm_transactions
WHERE transaction_type = "withdraw"
AND atm_location = "Leggett Street"
AND year = 2021
AND month = 7
AND day = 28;


--list of names matching the acc no.
SELECT name, atm_transactions.amount
FROM people
JOIN bank_accounts
ON people.id = bank_accounts.person_id
JOIN atm_transactions
ON bank_accounts.account_number = atm_transactions.account_number
WHERE atm_transactions.year = 2021
AND atm_transactions.month = 7
AND atm_transactions.day = 28
AND atm_transactions.atm_location = 'Leggett Street'
AND atm_transactions.transaction_type = 'withdraw';



--list of fligths out of fiftyville on 29/7/21
SELECT id, hour, minute, destination_airport_id FROM flights
WHERE flights.origin_airport_id = 8
AND year = 2021
AND month = 7
AND day = 29;


--earliest flight is id 36, to AIRPORT ID 4, LGA LaGuardia NYC




--List of ppl that are taking flight id 36
SELECT name, id FROM people, passengers
WHERE people.passport_number = passengers.passport_number
AND flight_id = 36;



-- PPL WHO MADE PHONE CALLS within that time frame
SELECT name, phone_calls.duration FROM people, phone_calls
WHERE people.phone_number = phone_calls.caller
AND year = 2021
AND month = 7
AND day = 28
AND duration <= 60;



-- PPL WHO RECEVIED PHONE CALLS within that time frame
SELECT name, phone_calls.duration FROM people, phone_calls
WHERE people.phone_number = phone_calls.receiver
AND year = 2021
AND month = 7
AND day = 28
AND duration <= 60;


---BRUCE and ROBIN has the same call time of 45
---SOFIA, JACK  51
---KELSEY, LARRY  36


--- BRUCE is especially suspicious since his name popped out many times.
-- The atm transaction, license plate of car registered to him when leaving bakery, and in on the earlierst flight out of Fiftyville to NYC the next day.
-- We can rule out that BRUCE is the thief. And since Robin was the one he called, Robin must be the accomplice that booked the plane ticket for him.

