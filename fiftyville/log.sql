--
SELECT description FROM crime_scene_reports
WHERE day = 28
AND month = 7
AND year = 2023;

SELECT transcript FROM interviews
WHERE day = 28
AND month = 7
AND year = 2023;



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

SELECT receiver
FROM phone_calls
WHERE day = 28
AND month = 7
AND year = 2023
AND duration < 60
AND caller IN
(
    SELECT phone_number FROM people
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
);

SELECT name, passport_number FROM people
JOIN phone_calls
ON people.phone_number = phone_calls.receiver
WHERE day = 28
AND month = 7
AND year = 2023
AND duration < 60
AND caller IN
(
    SELECT phone_number FROM people
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
);

SELECT name FROM people
JOIN phone_calls
ON people.phone_number = phone_calls.receiver
JOIN passengers
ON passengers.passport_number = people.passport_number
WHERE passengers.flight_id =
(
    SELECT id FROM flights
    WHERE flights.day = 29
    AND flights.month = 7
    AND flights.year = 2023
    ORDER BY flights.minute
    LIMIT 1;
)
AND phone_calls.day = 28
AND phone_calls.month = 7
AND phone_calls.year = 2023
AND phone_calls.duration < 60
AND phone_calls.caller IN
(
    SELECT phone_number FROM people
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
);










SELECT DISTINCT name FROM people
JOIN passengers
ON passengers.passport_number = people.passport_number
WHERE passengers.flight_id = 18
AND passengers.passport_number =
(
    SELECT people.passport_number
    FROM people
    WHERE people.phone_number =
    (
        SELECT phone_calls.receiver FROM phone_calls
        WHERE phone_calls.day = 28
        AND phone_calls.month = 7
        AND phone_calls.year = 2023
        AND phone_calls.duration < 60
        AND phone_calls.caller =
        (
            SELECT people.phone_number FROM people
            WHERE people.license_plate IN
            (
                SELECT license_plate
                FROM bakery_security_logs
                WHERE bakery_security_logs.day = 28
                AND bakery_security_logs.month = 7
                AND bakery_security_logs.year = 2023
                AND bakery_security_logs.hour = 10
                AND bakery_security_logs.minute >= 15
                AND bakery_security_logs.minute <= 25
            )
        )
    )
);


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
