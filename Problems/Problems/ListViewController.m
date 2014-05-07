
#import "ListViewController.h"

@implementation ListViewController
{
	NSMutableArray *list;
}

- (id)initWithStyle:(UITableViewStyle)style
{
	if (self == [super initWithStyle:style])
	{
		[list addObject:@"One"];
		[list addObject:@"Two"];
		[list addObject:@"Three"];
		[list addObject:@"Four"];
		[list addObject:@"Five"];
	}
	return self;
}

- (void)viewDidLoad
{
	[super viewDidLoad];
    NSLog(@"viewDidLoad is called");
}

- (void)viewDidUnload
{
	[super viewDidUnload];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
	return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

#pragma mark - Table view data source

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
	return 6;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
	static NSString *CellIdentifier = @"Cell";
	UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];

	cell.textLabel.text = [list objectAtIndex:indexPath.row];

	return cell;
}

- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
	if (editingStyle == UITableViewCellEditingStyleDelete)
	{
		[tableView deleteRowsAtIndexPaths:[NSArray arrayWithObject:indexPath] withRowAnimation:UITableViewRowAnimationFade];
	}   
}

@end
