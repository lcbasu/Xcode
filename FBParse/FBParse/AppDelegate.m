//
//  AppDelegate.m
//  FBParse
//

#import "AppDelegate.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // register the parse application
    [Parse setApplicationId:@"SCi48V6V3sPq8qfrnnbaBmbQudYgJouhpaMkRhdk" clientKey:@"qkYCHnq0ahWXFQunpO00Jx3Rddtay5qNdKy3Ecj0"];
    
    // initialize Parse's Facebook Utilities singleton
    [PFFacebookUtils initializeFacebook];
	return YES;
}

- (BOOL) application:(UIApplication *)application handleOpenURL:(NSURL *)url
{
    return [PFFacebookUtils handleOpenURL:url];
}

- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation
{
    return [PFFacebookUtils handleOpenURL:url];
}

@end
