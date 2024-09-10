--
SELECT description FROM crime_scene_reports
WHERE day = 28
AND month = 7
AND year = 2023;

SELECT transcript FROM interviews
WHERE day = 28
AND month = 7
AND year = 2023;

SELECT id FROM flights
WHERE day = 29
AND month = 7
AND year = 2023
ORDER BY minute
LIMIT 1;

SELECT city FROM airports
JOIN flights
ON airports.id = flights.destination_airport_id
WHERE flights.id = 18;

SELECT name, phone_number
FROM people
WHERE license_plate IN
(
    SELECT license_plate
    FROM bakery_security_logs
    WHERE day = 28
    AND month = 7
    AND year = 2023
    AND hour = 10
    AND minute >= 15
    AND minute <= 25
)
AND phone_number IN
(
    SELECT caller
    FROM phone_calls
    WHERE day = 28
    AND month = 7
    AND year = 2023
    AND duration < 60
);

SELECT name FROM people
JOIN passengers
ON passengers.passport_number = people.passport_number
JOIN flights ON flights.id = passengers.flight_id
JOIN phone_calls
ON people.phone_number = phone_calls.phone_number
WHERE flights.id = 18
AND passengers.passport_number =
(
    SELECT people.passport_number
    FROM people
    WHERE phone_calls.receiver =
    (
        SELECT phone_calls.receiver FROM phone_calls
        WHERE phone_calls.caller = 
    WHERE license_plate IN
    (
        SELECT license_plate
        FROM bakery_security_logs
        WHERE day = 28
        AND month = 7
        AND year = 2023
        AND hour = 10
        AND minute >= 15
        AND minute <= 25
    )
    AND phone_number IN
    (
        SELECT caller
        FROM phone_calls
        WHERE day = 28
        AND month = 7
        AND year = 2023
        AND duration < 60
    )
)


SELECT activity, license_plate, minute
FROM bakery_security_logs
WHERE day = 28
AND month = 7
AND year = 2023
AND hour = 10;



SELECT caller, receiver
FROM phone_calls
WHERE day = 28
AND month = 7
AND year = 2023
AND duration < 60;

SELECT account_number, transaction_type, amount
FROM atm_transactions
WHERE day = 28
AND month = 7
AND year = 2023;
