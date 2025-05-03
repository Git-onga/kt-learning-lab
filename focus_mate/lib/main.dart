import 'package:flutter/material.dart';
import 'package:focus_mate/screens/discover.dart';
import 'package:focus_mate/screens/home.dart';
import 'package:focus_mate/screens/profile.dart' show ProfileScreen;
import 'package:focus_mate/screens/report.dart' show ReportScreen;

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        primaryColor: Color(0xFF1A2B4C),
        scaffoldBackgroundColor: Color(0XFFF1F5F9),
        cardColor: Colors.white,
        textTheme: const TextTheme(
          bodyLarge: TextStyle(color: Color(0xFF1F2937)),
          bodyMedium: TextStyle(color: Color(0XFF6B7280)),
        ),
        colorScheme: ColorScheme.fromSwatch().copyWith(
          secondary: Color(0xFF4DB6AC),
          primary: Color(0xFF1A2B4C),
          onPrimary: Colors.white,
        ),
      ),
      home: MainPage(),
    );
  }
}

class SplashScreen extends StatefulWidget {
  const SplashScreen({super.key});

  @override
    State<SplashScreen> createState() => _SplashScreenState();

}

class _SplashScreenState extends State<SplashScreen>{
  @override
  Widget build(Object context) {
    return Scaffold(
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Icon(Icons.book),

            const Text(
              'FocusMate',
              style: TextStyle(
                fontSize: 60,
                fontWeight: FontWeight.bold,
                fontStyle: FontStyle.italic,
              ),
            )
          ],
        ),
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
    const DiscoverScreen(),
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
        selectedItemColor: const Color.fromARGB(255, 77, 182, 172),
        unselectedItemColor: Color.fromARGB(255, 26, 43, 76),
        items: const [
          BottomNavigationBarItem(icon: Icon(Icons.home, color: Colors.black,), label:  'Home') ,
          BottomNavigationBarItem(icon: Icon(Icons.explore, color: Colors.black,), label: 'Discover'),
          BottomNavigationBarItem(icon: Icon(Icons.bar_chart, color: Colors.black,), label: 'Report'),
          BottomNavigationBarItem(icon: Icon(Icons.person, color: Colors.black), label: 'Profile'),
        ],
      ),
    );
  }
}
