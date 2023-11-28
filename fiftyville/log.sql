-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Quering from the data as per the intel provided to get leads - 10:15am at the bakery.
SELECT * FROM crime_scene_reports
WHERE day = 28 AND month = 7 AND year = 2021 AND street = 'Humphrey Street';

-- Query from the interviews to find leads mentioning bakery
SELECT * FROM interviews
WHERE day = 28 AND month = 7 AND year = 2021;

-- Ruth's intel - Security footage 10 mins aftr CS
SELECT * FROM bakery_security_logs
WHERE hour = 10 AND day = 28 AND month = 7 AND year = 2021 AND activity = 'exit';

-- Searching all people affiliated with the license_plate from the query above. We got names of people.
SELECT * FROM people
WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs
WHERE hour = 10 AND day = 28 AND month = 7 AND year = 2021 AND activity = 'exit');

-- Eugene's intel
SELECT * FROM atm_transactions
WHERE atm_location = 'Leggett Street' AND day = 28 AND month = 7 AND year = 2021 AND transaction_type = 'withdraw';

-- We got account_number of 8 people. Lets query the bank_accounts and link it to people and lice_plate from Bakery logs
SELECT * FROM bank_accounts
WHERE account_number IN
    (SELECT account_number FROM atm_transactions
    WHERE atm_location = 'Leggett Street'
    AND day = 28 AND month = 7 AND year = 2021 AND transaction_type = 'withdraw')
    AND person_id IN
        (SELECT id FROM people
        WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs
        WHERE hour = 10 AND day = 28 AND month = 7 AND year = 2021 AND activity = 'exit'));

-- Linking the above shortlisted people with people_id to get the names
SELECT * FROM people
WHERE id IN (SELECT person_id FROM bank_accounts
WHERE account_number IN
    (SELECT account_number FROM atm_transactions
    WHERE atm_location = 'Leggett Street'
    AND day = 28 AND month = 7 AND year = 2021 AND transaction_type = 'withdraw')
    AND person_id IN
        (SELECT id FROM people
        WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs
        WHERE hour = 10 AND day = 28 AND month = 7 AND year = 2021 AND activity = 'exit')));

-- Linking the above output 'name' with 'caller' on phone_calls to narrow-down
SELECT * FROM phone_calls
JOIN people ON people.phone_number = phone_calls.caller
WHERE people.id IN (SELECT person_id FROM bank_accounts
WHERE account_number IN
    (SELECT account_number FROM atm_transactions
    WHERE atm_location = 'Leggett Street'
    AND day = 28 AND month = 7 AND year = 2021 AND transaction_type = 'withdraw')
    AND person_id IN
        (SELECT id FROM people
        WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs
        WHERE hour = 10 AND day = 28 AND month = 7 AND year = 2021 AND activity = 'exit')))
    AND day = 28 AND month = 7 AND year = 2021 AND duration < 60;

-- Getting id for fiftyville airport
SELECT * FROM airports
WHERE full_name LIKE 'Fiftyville%';


-- Enquiring flights. Earliest flight for 29th July
SELECT * FROM flights
WHERE origin_airport_id IN (SELECT id FROM airports
WHERE full_name LIKE 'Fiftyville%')
AND day = 29 AND month = 7 AND year = 2021 and hour < 9;

-- Earliest flight. Finding passengers linking with flight_id
SELECT * FROM passengers
WHERE flight_id == 36;

-- Compare passport numbers of the 3 shortlisted in above queries with the ones receivied in flight_id = 36 to get to the two names
SELECT * FROM people
WHERE passport_number IN (SELECT passport_number FROM passengers
WHERE flight_id == 36);


SELECT * FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
WHERE passengers.flight_id IN
(SELECT id FROM flights
WHERE origin_airport_id IN (SELECT id FROM airports
WHERE full_name LIKE 'Fiftyville%')
AND day = 29 AND month = 7 AND year = 2021 and hour < 9)
JOIN people ON people.phone_number = phone_calls.caller
WHERE people.id IN (SELECT person_id FROM bank_accounts
WHERE account_number IN
    (SELECT account_number FROM atm_transactions
    WHERE atm_location = 'Leggett Street'
    AND day = 28 AND month = 7 AND year = 2021 AND transaction_type = 'withdraw')
    AND person_id IN
        (SELECT id FROM people
        WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs
        WHERE hour = 10 AND day = 28 AND month = 7 AND year = 2021 AND activity = 'exit')))
    AND day = 28 AND month = 7 AND year = 2021 AND duration < 60;

SELECT name
FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
JOIN flights ON passengers.flight_id = flights.id
JOIN people ON people.phone_number = flights.caller
WHERE flights.id IN (
    SELECT flights.id
    FROM flights
    JOIN airports ON flights.origin_airport_id = airports.id
    WHERE airports.full_name LIKE 'Fiftyville%'
    AND flights.day = 29 AND flights.month = 7 AND flights.year = 2021 AND flights.hour < 9
)
AND people.id IN (
    SELECT people.id
    FROM bank_accounts
    JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
    JOIN people ON atm_transactions.person_id = people.id
    WHERE atm_transactions.atm_location = 'Leggett Street'
    AND atm_transactions.day = 28 AND atm_transactions.month = 7 AND atm_transactions.year = 2021
    AND atm_transactions.transaction_type = 'withdraw'
    AND people.id IN (
        SELECT people.id
        FROM people
        JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
        WHERE bakery_security_logs.hour = 10 AND bakery_security_logs.day = 28 AND bakery_security_logs.month = 7 AND bakery_security_logs.year = 2021
        AND bakery_security_logs.activity = 'exit'
    )
)
AND flights.day = 28 AND flights.month = 7 AND flights.year = 2021 AND flights.duration < 60;

-- Finalize the single person and connect his call with the receiver to find the accompliance as well as destination city

