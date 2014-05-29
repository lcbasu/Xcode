//  BeerViewController.m
//  Magical_Record
//  Copyright (c) 2013 Ray Wenderlich. All rights reserved.

#import "BeerViewController.h"
#import "AMRating/AMRatingControl.h"
#import "PhotoViewController.h"
#import "ImageSaver.h"
#import "Beer.h"
#import "BeerDetails.h"

@interface BeerViewController ()<UIGestureRecognizerDelegate, UIImagePickerControllerDelegate, UINavigationControllerDelegate, UIActionSheetDelegate>
@end


@implementation BeerViewController

- (void)viewDidLoad {
    if (!self.beer) {
        self.beer = [Beer createEntity];
    }
    // 2. If there are no beer details, create new BeerDetails
    if (!self.beer.beerDetails) {
        self.beer.beerDetails = [BeerDetails createEntity];
    }
    // View setup
    // 3. Set the title, name, note field and rating of the beer
    self.title = self.beer.name ? self.beer.name : @"New Beer";
    self.beerNameField.text = self.beer.name;
    self.beerNotesView.text = self.beer.beerDetails.note;
    self.ratingControl.rating = [self.beer.beerDetails.rating integerValue];
    [self.cellOne addSubview:self.ratingControl];
    
    // 4. If there is an image path in the details, show it.
    if ([self.beer.beerDetails.image length] > 0) {
        // Image setup
        NSData *imgData = [NSData dataWithContentsOfFile:[NSHomeDirectory() stringByAppendingPathComponent:self.beer.beerDetails.image]];
        [self setImageForBeer:[UIImage imageWithData:imgData]];
    }
}

- (void)setImageForBeer:(UIImage*)img {
	self.beerImage.image		   = img;
	self.beerImage.backgroundColor = [UIColor clearColor];
	self.tapToAddLabel.hidden	   = YES;
}

- (void)viewWillDisappear:(BOOL)animated {
	[super viewWillDisappear:animated];
	[self.beerNameField resignFirstResponder];
	[self.beerNotesView resignFirstResponder];
	// Save context as view disappears
	[self saveContext];
}

- (void)cancelAdd {
	[self.navigationController popViewControllerAnimated:YES];
}

- (void)addNewBeer {
	[self.navigationController popViewControllerAnimated:YES];
}

- (void)saveContext {
    
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
	PhotoViewController *upcoming = segue.destinationViewController;
	upcoming.image = self.beerImage.image;
}

#pragma mark - Rating Control
// Setup rating control
- (AMRatingControl*)ratingControl {
	if (!_ratingControl) {
		_ratingControl = [[AMRatingControl alloc] initWithLocation:CGPointMake(95,66)
														emptyImage:[UIImage imageNamed:@"beermug-empty"]
														solidImage:[UIImage imageNamed:@"beermug-full"]
													  andMaxRating:5];
		_ratingControl.starSpacing = 5;
		[_ratingControl addTarget:self
						   action:@selector(updateRating)
				 forControlEvents:UIControlEventEditingChanged];
	}
	return _ratingControl;
}

// Updates rating
- (void)updateRating {
	
}

#pragma mark - TextField & TextView Delegate
- (IBAction)didFinishEditingBeer:(id)sender {
	[self.beerNameField resignFirstResponder];
}

- (void)textFieldDidEndEditing:(UITextField *)textField {
	if ([textField.text length] > 0) {
		self.title     = textField.text;
	}
}

- (void)textViewDidEndEditing:(UITextView *)textView {
	[textView resignFirstResponder];
	if ([textView.text length] > 0) {
		
	}
}

#pragma mark - Image capture
- (IBAction)takePicture:(UITapGestureRecognizer*)sender {
	UIActionSheet *sheet;
	sheet = [[UIActionSheet alloc] initWithTitle:@"Pick Photo"
										delegate:self
							   cancelButtonTitle:@"Cancel"
						  destructiveButtonTitle:nil
							   otherButtonTitles:@"Take Photo", @"Choose Photo", nil];
	
	[sheet showInView:self.navigationController.view];
}

- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker {
	[picker dismissViewControllerAnimated:YES completion:nil];
}

- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info {
	[picker dismissViewControllerAnimated:YES completion:nil];
}

#pragma mark - UIActionSheet Delegate
- (void)actionSheet:(UIActionSheet *)actionSheet didDismissWithButtonIndex:(NSInteger)buttonIndex {
	UIImagePickerController *imagePicker = [[UIImagePickerController alloc] init];
	imagePicker.delegate = self;
	switch (buttonIndex) {
		case 0: {
			if ([UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera]) {
				imagePicker.sourceType = UIImagePickerControllerSourceTypeCamera;
				[self presentViewController:imagePicker animated:YES completion:nil];
			}
		}
			break;
		case 1: {
			imagePicker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
			[self presentViewController:imagePicker animated:YES completion:nil];
		}
			break;
		default:
			break;
	}
}

@end
