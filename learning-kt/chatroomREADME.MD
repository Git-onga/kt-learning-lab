Add the necessary dependencies in your build.gradle.kts:

dependencies {
    implementation(compose.desktop.currentOs)
    implementation("org.jetbrains.kotlinx:kotlinx-coroutines-core:1.6.4")
}
