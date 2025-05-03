import 'package:flutter/material.dart';
import 'package:talli_app/Screens/home.dart';
import 'package:talli_app/Screens/schedule.dart';
import 'package:talli_app/Screens/profile.dart';
import 'package:talli_app/Screens/report.dart';
import 'dart:async';


void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: const SplashScreen(),
    );
  }
}

class SplashScreen extends StatefulWidget {
  const SplashScreen({super.key});

  @override
  State<SplashScreen> createState() => _SplashScreenState();
}

class _SplashScreenState extends State<SplashScreen> with TickerProviderStateMixin {
  late AnimationController _lineController;
  late AnimationController _textController;
  late Animation<double> _lineAnimation;
  late Animation<double> _textAnimation;

  @override
  void initState() {
    super.initState();

    _lineController = AnimationController(
      vsync: this,
      duration: const Duration(seconds: 2),
    );

    _textController = AnimationController(
      vsync: this,
      duration: const Duration(seconds: 1),
    );

    _lineAnimation = Tween<double>(begin: 0.0, end: 0.6).animate(CurvedAnimation(
      parent: _lineController,
      curve: Curves.easeInOut,
    ));

    _textAnimation = Tween<double>(begin: -120, end: 0).animate(CurvedAnimation(
      parent: _textController,
      curve: Curves.bounceOut,
    ));

    _lineController.forward().whenComplete(() {
      _textController.forward().whenComplete(() {
        Future.delayed(const Duration(seconds: 1), (){
          Navigator.pushReplacement(
            // ignore: use_build_context_synchronously
            context, 
            MaterialPageRoute(builder: (context) => const MainPage()),
          );
        });
      });
    });
  }

  @override
  void dispose() {
    _lineController.dispose();
    _textController.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.white,
      body: AnimatedBuilder(
        animation: Listenable.merge([_lineController, _textController]),
        builder: (context, child) {
          return Center(
            child: Stack(
              alignment: Alignment.topCenter,
              children: [
                // Line Drawing Across
                Positioned(
                  top: MediaQuery.of(context).size.height * 0.4,
                  child: Container(
                    height: 7, // <- Thickness
                    width: MediaQuery.of(context).size.width * _lineAnimation.value,
                    color: const Color.fromARGB(255, 8, 153, 13),
                  ),
                ),

                // Dropping Text
                Positioned(
                  top: MediaQuery.of(context).size.height * 0.4 + _textAnimation.value,
                  child: Opacity(
                    opacity: ((_textAnimation.value + 100) / 100).clamp(0.0, 1.0),
                    child: Text(
                    'Talli',
                    style: const TextStyle(
                      fontSize: 100,
                      fontWeight: FontWeight.bold,
                      fontStyle: FontStyle.italic,
                      color: Colors.deepOrange,
                    ),
                  ),
                  )
                ),
              ],
            ),
          );
        },
      ),
    );
  }
}

class MainPage extends StatefulWidget {
  const MainPage({super.key});

  @override
  State<MainPage> createState() => _MainPageState();
}

class _MainPageState extends State<MainPage> {
  int _currentIndex = 0;

  final List<Widget> _pages = [
    const HomeScreen(),
    const ScheduleScreen(),
    const ReportScreen(),
    const ProfileScreen(),
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: _pages[_currentIndex],
      bottomNavigationBar: BottomNavigationBar(
        type: BottomNavigationBarType.fixed,
        currentIndex: _currentIndex,
        onTap: (index) => setState(() => _currentIndex = index),
        selectedItemColor: Colors.deepOrange,
        unselectedItemColor: Color.fromARGB(255, 8, 153, 13),
        items: const [
          BottomNavigationBarItem(icon: Icon(Icons.home, color: Colors.black,), label:  'Home') ,
          BottomNavigationBarItem(icon: Icon(Icons.calendar_month, color: Colors.black,), label: 'Schedule'),
          BottomNavigationBarItem(icon: Icon(Icons.bar_chart, color: Colors.black,), label: 'Report'),
          BottomNavigationBarItem(icon: Icon(Icons.person, color: Colors.black), label: 'Profile'),
        ],
      ),
    );
  }
}
