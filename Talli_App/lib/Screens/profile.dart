import 'package:flutter/material.dart';

class ProfileScreen extends StatelessWidget {
  const ProfileScreen({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Positioned(
              child: Column(
                children: [
                  Icon(
                    Icons.person,
                    color: Color.fromARGB(255, 8, 153, 13),
                    size: 100,
                  ),
                  Text(
                    "Profile",
                    style: TextStyle(
                      fontStyle: FontStyle.italic,
                      color: Colors.deepOrange,
                      fontSize: 80
                    ),
                  )
                ],
              )
            )
            
          ],
        ),
      ),
    );
  }
}
